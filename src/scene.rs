
use crate::math::Vector;
use crate::math::Matrix;
use crate::rendering::Color;
use crate::rendering::Lightsource;
use crate::rendering::Object;
use crate::tde::Ray;
use std::vec::Vec;
use image::{RgbImage, Rgb};

pub struct Scene {
    pub ambient_light_color: Color,
    pub camera: Camera,
    pub objects: Vec<Object>,
    pub lightsource: Box<dyn Lightsource>,
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
    fn trace_ray(&self, ray: Ray, trace_limit: u64) -> Color {
        let (mut d, mut p, mut n): (bool, Vector, Vector) = (false, Vector::default(), Vector::default());
        let mut min_distance: f64;
        let mut cur_distance: f64;
        let mut ray_segment: Vector;
        let mut incid: std::option::Option<&Object>;
        let mut out_color: Color = Color::zero();

        p = ray.o;
        n = ray.d;
        min_distance = 0.0;
        incid = None;
        for object in &self.objects {
            let (d, pp, nn) = object.s.intersect(&ray);
            if d == true {
                ray_segment = pp - self.camera.origin;
                cur_distance = ray_segment * ray_segment;
                if min_distance == 0.0 || cur_distance < min_distance {
                    min_distance = cur_distance;
                    incid = Some(object);
                    p = pp;
                    n = nn;
                }
            }
        }

        if (ray.d * n).is_sign_positive() {
            n = -n;
        }

        if incid.is_some() {
            out_color = incid.unwrap().m.base_color;
            if trace_limit > 1 {
                let (source_index, mut target_index): (f64, f64) = (ray.i, incid.unwrap().m.refractive_index);
                if source_index == target_index {
                    target_index = 1.0;
                }
                
                // Schlick's Approximation
                // let r0: f64 = ((source_index - target_index) / (source_index + target_index)).powf(2.0);
                // let reflected_thet: f64 = r0 + (1.0 - r0) * (1.0 - (-ray.d) * n).powf(5.0);
                // let refracted_thet: f64 = 1.0 - reflected_thet;

                let reflected: f64 = incid.unwrap().m.opacity;
                let transmitted: f64 = 1.0 - reflected;
                let mut reflected_contribution: Color = Color::default();
                let mut transmitted_contribution: Color = Color::default();

                if transmitted != 0.0 {
                    let refracted_ray: Ray = Ray::new(p, ray.refracted_direction(n, source_index, target_index), Color { r: 1.0, g: 1.0, b: 1.0 }, target_index);
                    transmitted_contribution = self.trace_ray(refracted_ray, trace_limit - 1);
                }

                if reflected != 0.0 {
                    let reflected_ray: Ray = Ray::new(p, ray.reflected_direction(n), Color {r: 1.0, g: 1.0, b: 1.0}, ray.i);
                    reflected_contribution = self.trace_ray(reflected_ray, trace_limit - 1);
                }

                out_color *=  incid.unwrap().m.base_color * reflected * reflected_contribution + transmitted * transmitted_contribution;
            }
        } else {
            let (light_dir, light_intensity, light_color) = self.lightsource.get_light(p);
            
            if (light_dir * ray.d).is_sign_negative() {
                out_color = light_color * f64::max(-light_dir * ray.d, 0.0) * light_intensity;
            }
            out_color += self.ambient_light_color;
        }

        return out_color;
    }

    pub fn render(&self, mut trace_limit: u64) {
        let mut image: RgbImage = RgbImage::new(self.camera.width as u32, self.camera.height as u32);
        let (mut r, mut g, mut b): (u8, u8, u8);
        let mut out_color: Color;
        let mut ray: Ray;

        for row in 0..self.camera.height {
            for col in 0..self.camera.width {
                ray = self.camera.get_ray(row as f64, col as f64);
                out_color = self.trace_ray(ray, trace_limit);

                r = u8::min((out_color.r * 255.0) as u8, 255);
                g = u8::min((out_color.g * 255.0) as u8, 255);
                b = u8::min((out_color.b * 255.0) as u8, 255);
                image.put_pixel(col as u32, row as u32, Rgb([r, g, b]));
            } 
        }
        image.save("output.png").unwrap();
    }
}
