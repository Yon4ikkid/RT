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

impl ops::Mul for Color {
    type Output = Color;

    fn mul(self, other: Color) -> Self::Output {
        return Color { r: self.r * other.r,g: self.g * other.g,b: self.b * other.b };
    }
}

impl ops::MulAssign for Color {
    fn mul_assign(&mut self, rhs: Self) {
        self.r *= rhs.r;
        self.g *= rhs.g;
        self.b *= rhs.b;
    }
}

pub struct Material {
    pub base_color: Color,
    pub refractive_index: f64,
    pub reflection_ratio: f64,
}

pub struct Object {
    pub m: Material,
    pub s: Box<dyn Intersectable>,
}

pub trait Intersectable {
    fn intersect(&self, r: &Ray) -> (bool, Vector, Vector);
}

