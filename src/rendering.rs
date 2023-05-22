use crate::tde::Ray;
use crate::math::Vector;
use std::boxed::Box;
use std::ops;

#[derive(Copy, Clone)]
pub struct Color {
    pub r: f64,
    pub g: f64,
    pub b: f64,
}

impl Color {
    pub fn new(r: f64, g: f64, b: f64) -> Color {
        return Color { r, g, b };
    }

    pub fn default() -> Color {
        return Color { r: 1.0, g: 1.0, b: 1.0 };
    }

    pub fn zero() -> Color {
        return Color { r: 0.0, g: 0.0, b: 0.0 };
    }

    pub fn magnitude(self) -> f64 {
        return (self.r * self.r + self.b * self.b + self.g * self.g).sqrt();
    }
}

impl ops::Add for Color {
    type Output = Color;

    fn add(self, other: Color) -> Self::Output {
        // return Color {
        //     r: f64::min(self.r + other.r, 1.0),
        //     g: f64::min(self.g + other.g, 1.0),
        //     b: f64::min(self.b + other.b, 1.0)
        // };
        return Color {
            r: self.r + other.r,
            g: self.g + other.g,
            b: self.b + other.b
        };
    }
}

impl ops::AddAssign for Color {
    fn add_assign(&mut self, rhs: Self) {
        self.r = f64::min(self.r + rhs.r, 1.0);
        self.g += f64::min(self.g + rhs.g, 1.0);
        self.b += f64::min(self.b + rhs.b, 1.0);
    }
}

impl ops::Mul for Color {
    type Output = Color;

    fn mul(self, other: Color) -> Self::Output {
        return Color { r: self.r * other.r,g: self.g * other.g,b: self.b * other.b };
    }
}

impl ops::Mul<f64> for Color {
    type Output = Color;

    fn mul(self, other: f64) -> Self::Output {
        return Color { r: self.r * other,g: self.g * other,b: self.b * other };
    }
}

impl ops::Mul<Color> for f64 {
    type Output = Color;

    fn mul(self, other: Color) -> Self::Output {
        return Color { r: self * other.r,g: self * other.g ,b: self * other.b };
    }
}

impl ops::MulAssign for Color {
    fn mul_assign(&mut self, rhs: Self) {
        self.r *= rhs.r;
        self.g *= rhs.g;
        self.b *= rhs.b;
    }
}

impl ops::MulAssign<f64> for Color {
    fn mul_assign(&mut self, rhs: f64) {
        self.r *= rhs;
        self.g *= rhs;
        self.b *= rhs;
    }
}

pub struct Material {
    pub base_color: Color,
    pub refractive_index: f64,
    pub opacity: f64,
    pub roughness: f64,
}

pub struct Object {
    pub m: Material,
    pub s: Box<dyn Intersectable>,
}

pub trait Intersectable {
    fn intersect(&self, r: &Ray) -> (bool, Vector, Vector);
}

pub trait Lightsource {
    fn get_light(&self, p: Vector) -> (Vector, f64, Color);
}

pub struct DirectionalLight {
    pub c: Color,
    pub d: Vector
}

pub struct PointLight {
    pub c: Color,
    pub o: Vector,
    pub d: f64,
}

impl Lightsource for DirectionalLight {
    fn get_light(&self, _p: Vector) -> (Vector, f64, Color) {
        return (self.d, 1.0, self.c);
    }
}

impl Lightsource for PointLight {
    fn get_light(&self, p: Vector) -> (Vector, f64, Color) {
        let v = p - self.o;
        return (v.unit(), f64::clamp(1.0 - v.norm() / self.d, 0.0, 1.0), self.c);
    }
}
