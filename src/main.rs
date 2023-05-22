use math::Vector;
use rendering::{Object, Material, Color, PointLight, DirectionalLight};
use tde::Sphere;

use crate::tde::Plane;

pub mod math;
pub mod tde;
pub mod rendering;
pub mod scene;

fn main() {
    // std::env::set_var("RUST_BACKTRACE", "1");
    const AMB: f64 = 0.001;
    let c: scene::Camera = scene::Camera::new(600, 600, 2000.0, math::Vector {x: 0.0, y: -2000.0, z: 0.0}, 0.0, 0.0, 0.0);
    let mut s: scene::Scene = scene::Scene { ambient_light_color: rendering::Color { r: AMB, g:AMB, b: AMB }, camera: c, objects: std::vec::Vec::new(),
                                            //  lightsource: Box::new(PointLight {c: Color { r: 1.0, g: 1.0, b: 1.0 } , o: Vector { x: 400.0, y: 75.0, z: 70.0 }, d: 800.0 }) };
                                            lightsource: Box::new(DirectionalLight {c: Color { r: 1.0, g: 1.0, b: 1.0 } , d: Vector { x: -0.5, y: 0.15, z: -1.0 }.unit()}) };
    let o: Object = Object { m: Material { base_color: Color {r: 1.0, g: 0.1, b: 0.1}, 
        refractive_index: 1.0, opacity: 1.0, roughness: 1.0}, s: Box::new(Sphere { c: Vector { x: -80.0, y: 90.0, z: -60.0 }, r: 65.0 }) };
    let o1: Object = Object { m: Material { base_color: Color {r: 0.1, g: 0.1, b: 0.9}, 
        refractive_index: 1.5, opacity: 1.0, roughness: 1.0}, s: Box::new(Sphere { c: Vector { x: 20.0, y: 250.0, z: -14.0 }, r: 80.0 }) };
    let o2: Object = Object { m: Material { base_color: Color {r: 1.0, g: 1.0, b: 1.0}, 
        refractive_index: 1.0, opacity: 1.0, roughness: 0.5}, s: Box::new(Plane { a: Vector { x: 20.0, y: 250.0, z: -180.0 }, n: Vector { x: 0.0, y: 0.0, z: 1.0 }.unit() }) };
    let o3: Object = Object { m: Material { base_color: Color {r: 0.3, g: 0.5, b: 0.5}, 
        refractive_index: 1.0, opacity: 1.0, roughness: 0.2}, s: Box::new(Plane { a: Vector { x: 20.0, y: 600.0, z: -300.0 }, n: Vector { x: 0.5, y: -1.01, z: 0.05 }.unit() }) };
    s.objects.push(o);
    s.objects.push(o1);
    // s.objects.push(o2);
    // s.objects.push(o3);
    s.render(5);
}
