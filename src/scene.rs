use crate::math::Vector;
use crate::math::Matrix;
use crate::rendering::Color;
use crate::rendering::Object;
use crate::tde::Ray;
use std::vec::Vec;

pub struct Scene<'a> {
    pub ambient_light_color: Color,
    pub camera: Camera,
    pub objects: Vec<Object<'a>>,
    pub lightsource: Box<dyn Lightsource + Sync>,
}

pub struct Camera {
    pub origin: Vector,
    pivot: Vector,
    right: Vector,
    down: Vector,
    pub focal_distance: f64,
    pub width: u32,
    pub height: u32,
}

impl Camera {
    fn empty() -> Camera {
        return Camera {
            origin: Vector::default(),
            pivot: Vector::default(),
            right: Vector::default(),
            down: Vector::default(),
            focal_distance: 0.0,
            width: 0,
            height: 0,
        };
    }

    pub fn new(height: u32, width: u32, fd: f64, origin: Vector, x_rot: f64, y_rot: f64, z_rot: f64) -> Camera {
        let mut cam: Camera = Camera::empty();
        cam.focal_distance = fd;
        cam.origin = origin;
        cam.width = width;
        cam.height = height;

        let mut a: Vector = Vector::new(-(width as f64) * 0.5, fd, (height as f64) * 0.5);
        let mut b: Vector = Vector::new((width as f64) * 0.5, fd, (height as f64) * 0.5);
        let mut c: Vector = Vector::new(-(width as f64) * 0.5, fd, -(height as f64) * 0.5);

        const RAD_CONV: f64 = 3.1415926535 / 180.0;
        let z_rad: f64 = -z_rot * RAD_CONV;
        let y_rad: f64 = -y_rot * RAD_CONV;
        let x_rad: f64 = -x_rot * RAD_CONV;
        
        let sin_a: f64 = z_rad.sin();
        let sin_b: f64 = y_rad.sin();
        let sin_g: f64 = x_rad.sin();
        let cos_a: f64 = z_rad.cos();
        let cos_b: f64 = y_rad.cos();
        let cos_g: f64 = x_rad.cos();

        let mut rm: Matrix = Matrix::new(3, 3);
        rm.values[0][0] = cos_a * cos_b;
        rm.values[0][1] = cos_a * sin_b * sin_g - sin_a * cos_g;
        rm.values[0][2] = cos_a * sin_b * cos_g + sin_a * sin_g;
        rm.values[1][0] = sin_a * cos_b;
        rm.values[1][1] = sin_a * sin_b * sin_g + cos_a * cos_g;
        rm.values[1][2] = sin_a * sin_b * cos_g - cos_a * sin_g;
        rm.values[2][0] = -sin_b;
        rm.values[2][1] = cos_b * sin_g;
        rm.values[2][2] = cos_b * cos_g;

        a = rm * a + origin;
        b = rm * b + origin;
        c = rm * c + origin;
        
        cam.right = (b - a).unit();
        cam.down = (c - a).unit();
        cam.pivot = a - origin;
        
        return cam;
    }

    pub fn get_ray(&self, row: f64, col: f64) -> Ray {
        return Ray::new(self.origin, (self.pivot + self.right * (col + 0.5) + self.down * (row + 0.5)).unit(), 1.0);
    }
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
