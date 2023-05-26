use crate::tde::Ray;
use crate::math::Vector;
use std::{boxed::Box, f64::consts::PI, thread::{JoinHandle, self}, sync::{Arc, Mutex}};
use crate::scene::Scene;
use std::vec::Vec;
use image::{RgbImage, Rgb};

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
    pub s: Box<dyn Intersectable + Sync>,
}

pub trait Intersectable {
    fn intersect(&self, r: &Ray) -> Option<f64>;
    fn get_normal(&self, p: Vector) -> Vector;
}

/// Renders the given scene into the image file
/// 
/// # Arguments
/// 
/// * `sc` - Target scene
/// * `trace_limit` - The depth limit of the rendering process
pub fn render(sc: &Scene, trace_limit: u64, n_workers: u32) {
    let image: RgbImage = RgbImage::new(sc.camera.width, sc.camera.height);
    let height: u32 = sc.camera.height;

    let async_ref = Arc::new(Mutex::new(image));

    if n_workers > sc.camera.height {
        panic!("Worker number exceeds camera height!");
    }

    let lines_per_worker: u32 = height / n_workers;
    let mut lines_issued: u32 = 0;

    thread::scope(|s| {
        for _ in 0..(n_workers - 1) {
            let local_ref = async_ref.clone();
            s.spawn(move || { workplace(sc, trace_limit, local_ref, lines_issued, lines_issued + lines_per_worker)} );
            lines_issued += lines_per_worker;
        }
        let local_ref = async_ref.clone();
        s.spawn(move || workplace(sc, trace_limit, local_ref, lines_issued, height));
    });

    async_ref.lock().unwrap().save("output.png").unwrap();
}

fn workplace(sc: &Scene, trace_limit: u64, image_arc: Arc<Mutex<RgbImage>>, s: u32, e: u32) {
    let (mut r, mut g, mut b): (u8, u8, u8);
    let mut ray: Ray;
    let mut out_color: Vector;

    
    for row in s..e {
        for col in 0..sc.camera.width {
            ray = sc.camera.get_ray(row as f64, col as f64);
            out_color = trace_ray(sc, &ray, trace_limit);

            r = u8::min((out_color.x * 255.0) as u8, 255);
            g = u8::min((out_color.y * 255.0) as u8, 255);
            b = u8::min((out_color.z * 255.0) as u8, 255);

            let mut image = image_arc.lock().unwrap();
            image.put_pixel(col, row, Rgb([r, g, b]));
        } 
    }
}

/// Finds the closest intersection (object, point and normal) of the ray with an object cluster
/// 
/// # Arguments
/// 
/// * `objects` - Vector containing the cluster objects
/// * `ray` - The target ray
fn find_closest_intersection<'a>(objects: &'a Vec<Object>, ray: &Ray) -> Option<(&'a Object, Vector, Vector)> {
    let mut current_t: f64;
    let mut smallest_t: f64 = f64::MAX;
    let mut obj_ref_op: Option<&Object> = None;

    for object in objects {
        let opt = object.s.intersect(&ray);

        if opt.is_some() {
            current_t = opt.unwrap();

            if current_t < smallest_t {
                smallest_t = current_t;
                obj_ref_op = Some(object);
            }
        }
    }

    if obj_ref_op.is_none() {
        return None;
    }

    let (p, obj_ref) = (ray.get_point(smallest_t), obj_ref_op.unwrap());
    return Some((obj_ref, p, obj_ref.s.get_normal(p)));
}

/// Trace the path of a given ray in the scene
/// 
/// # Arguments
/// 
/// * `sc` - Target scene
/// * `ray` - Ray to trace
/// * `depth` - Maximal tracing depth (i.e. incidence scattering)
fn trace_ray(sc: &Scene, ray: &Ray, depth: u64) -> Color {
    let mut out_color: Vector = Vector::default();
    
    let int_op = find_closest_intersection(&sc.objects, ray);

    if int_op.is_none() {
        let (light_dir, light_intensity, light_color) = sc.lightsource.get_light(ray.o);
        
        if (light_dir * ray.d).is_sign_negative() {
            out_color = light_color * f64::max(-light_dir * ray.d, 0.0) * light_intensity;
        }

        return out_color + sc.ambient_light_color;
    }

    let (obj, p, mut n): (&Object, Vector, Vector) = int_op.unwrap();

    if (ray.d * n).is_sign_positive() {
        n = -n;
    }

    if depth == 1 {
        return obj.m.emitted_color * (-ray.d * n);
    }

    let (source_index, mut target_index): (f64, f64) = (ray.i, obj.m.refractive_index);
    if source_index == target_index {
        target_index = 1.0;
    }
    
    // Schlick's Approximation
    // let r0: f64 = ((source_index - target_index) / (source_index + target_index)).powf(2.0);
    // let reflected: f64 = r0 + (1.0 - r0) * (1.0 - (-ray.d) * n).powf(5.0);
    // let transmitted: f64 = 1.0 - reflected;

    let reflected: f64 = obj.m.opacity;
    let transmitted: f64 = 1.0 - reflected;
    let mut reflected_contribution: Vector = Vector::default();
    let mut transmitted_contribution: Vector = Vector::default();

    if transmitted != 0.0 {
        let refracted_ray: Ray = Ray::new(p, ray.refracted_direction(n, source_index, target_index), target_index);
        transmitted_contribution = trace_ray(sc, &refracted_ray, depth - 1);
    }

    if reflected != 0.0 {
        const DIFF_DENSITY: f64 = 2.0;

        let rz: Vector = ray.reflected_direction(n);
        let rx: Vector = -rz.cross(n).unit();
        let ry: Vector = -rx.cross(rz).unit();
        let in_angle: f64 = (-ray.d * n).acos();
        let deviation: f64 = obj.m.roughness;
        let diff_div: i64 = (DIFF_DENSITY * deviation) as i64; 

        let f = |x: f64| -> f64 {
            f64::exp(- (1.0 / (deviation + 0.01)) * (x).powf(2.0)) * (in_angle - PI / 2.0 * deviation).cos()
        };

        let deviation_step: f64;
        if diff_div == 0 {
            deviation_step = 0.0;
        } else {
            deviation_step = 1.0 / (diff_div as f64);
        }
        
        let mut coef_sum: f64 = 0.0;
        let mut scr: Ray = Ray::new(p, Vector::default(), ray.i);
        for h in -diff_div..(diff_div + 1) {
            let u: f64 = h as f64 * deviation_step;
            let l1: f64 = f(u);
            for v in -diff_div..(diff_div + 1) {
                let s: f64 = v as f64 * deviation_step;
                let coef: f64 =  l1 * f(s);

                let c1: f64 = (-0.5 * PI * s * deviation).sin();
                let c2: f64 = (in_angle - 0.25 * PI * u * deviation).sin();
                let c3: f64 = (in_angle - 0.25 * PI * u * deviation).cos();

                scr.d = (c1 * rx + c2 * ry + c3 * rz).unit();
                
                let traced_color: Vector = trace_ray(sc, &scr, depth - 1);
                
                reflected_contribution += traced_color * coef;//* traced_color.magnitude();
                coef_sum += coef;
            }
        }
        reflected_contribution *= 1.0 / coef_sum;
    }

    return reflected * reflected_contribution.ewm(obj.m.reflected_color) + transmitted * transmitted_contribution.ewm(obj.m.transmitted_color) + (-ray.d * n) * obj.m.emitted_color;
}
