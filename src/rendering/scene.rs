use super::Color;
use crate::math::Vector;
use super::Camera;
use super::Object;

pub struct Scene<'a> {
    pub ambient_light_color: Color,
    pub camera: Camera,
    pub objects: Vec<Object<'a>>,
    pub lightsource: Box<dyn Lightsource + Sync>,
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