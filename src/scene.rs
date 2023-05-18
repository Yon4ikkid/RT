
use crate::math::Vector;
use crate::math::Matrix;
use crate::rendering::Color;
use crate::rendering::Object;
use crate::tde::Ray;
use std::vec::Vec;
use image::{RgbImage, Rgb};

pub struct Scene {
    pub ambient_light_color: Color,
    pub camera: Camera,
    pub objects: Vec<Object>,
}

pub struct Camera {
    origin: Vector,
    pivot: Vector,
    right: Vector,
    down: Vector,
    focal_distance: f64,
    pub width: usize,
    pub height: usize,
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

    pub fn new(height: usize, width: usize, fd: f64, origin: Vector, x_rot: f64, y_rot: f64, z_rot: f64) -> Camera {
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
        return Ray::new(self.origin, (self.pivot + self.right * (col + 0.5) + self.down * (row + 0.5)).unit(), Color { r: 1.0, g: 1.0, b: 1.0 }, 1.0);
    }
}

impl Scene { 
    pub fn render(&self, mut trace_limit: u64) {
        let mut image: RgbImage = RgbImage::new(self.camera.width as u32, self.camera.height as u32);
        let (mut r, mut g, mut b): (u8, u8, u8);
        let mut out_color: Color;
        let mut ray: Ray;
        let (mut d, mut p, mut n): (bool, Vector, Vector);
        let mut min_distance: f64;
        let mut cur_distance: f64;
        let mut ray_segment: Vector;
        let mut incid: std::option::Option<&Object>;

        if trace_limit == 0 {
            trace_limit = 1;
        }

        for row in 0..self.camera.height {
            for col in 0..self.camera.width {
                out_color = Color {r: 1.0, g: 1.0, b: 1.0};
                ray = self.camera.get_ray(row as f64, col as f64);
                
                for _ in 0..trace_limit {
                    min_distance = 0.0;
                    incid = None;
                    for object in &self.objects {
                        (d, p, n) = object.s.intersect(&ray);
                        if d == true {
                            ray_segment = p - self.camera.origin;
                            cur_distance = ray_segment * ray_segment;
                            if min_distance == 0.0 || cur_distance < min_distance {
                                min_distance = cur_distance;
                                incid = Some(object);
                            }
                        }
                    }
                    
                    if incid.is_some() {
                        out_color.r *= incid.unwrap().m.base_color.r;
                        out_color.g *= incid.unwrap().m.base_color.g;
                        out_color.b *= incid.unwrap().m.base_color.b;
                    } else {
                        out_color.r *= self.ambient_light_color.r;
                        out_color.g *= self.ambient_light_color.g;
                        out_color.b *= self.ambient_light_color.b;
                        break;
                    }
                }

                r = (out_color.r * 255.0) as u8;
                g = (out_color.g * 255.0) as u8;
                b = (out_color.b * 255.0) as u8;
                image.put_pixel(col as u32, row as u32, Rgb([r, g, b]));
            } 
        }
        image.save("output.png").unwrap();
    }
}
