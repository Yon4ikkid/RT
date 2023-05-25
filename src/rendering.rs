use crate::tde::Ray;
use crate::math::Vector;
use std::boxed::Box;

pub type Color = Vector;

pub struct Material {
    pub reflected_color: Color,
    pub transmitted_color: Color,
    pub emitted_color: Color,
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
