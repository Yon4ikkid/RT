use crate::tde::Ray;
use crate::math::Vector;
use std::boxed::Box;

pub struct Color {
    pub r: f64,
    pub g: f64,
    pub b: f64,
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

