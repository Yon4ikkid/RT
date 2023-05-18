use math::Vector;
use rendering::{Object, Material, Color, PointLight, DirectionalLight};
use tde::Sphere;

use crate::tde::Plane;

pub mod math;
pub mod tde;
pub mod rendering;
pub mod scene;

fn main() {
    std::env::set_var("RUST_BACKTRACE", "1");
    const AMB: f64 = 0.52;
    let c: scene::Camera = scene::Camera::new(300, 300, 1000.0, math::Vector {x: 0.0, y: -600.0, z: 0.0}, 0.0, 0.0, 0.0);
    let mut s: scene::Scene = scene::Scene { ambient_light_color: rendering::Color { r: AMB, g:AMB, b: AMB }, camera: c, objects: std::vec::Vec::new(),
                                            //  lightsource: Box::new(PointLight {c: Color { r: 1.0, g: 1.0, b: 1.0 } , o: Vector { x: 0.0, y: 50.0, z: 70.0 }, d: 1500.0 }) };
                                            lightsource: Box::new(DirectionalLight {c: Color { r: 0.0, g: 0.2, b: 0.2 } , d: Vector { x: 3.0, y: 1.01, z: -2.5 }.unit()}) };
    let o: Object = Object { m: Material { base_color: Color {r: 0.8, g: 0.4, b: 0.3}, 
        refractive_index: 0.86, reflection_ratio: 0.8}, s: Box::new(Sphere { c: Vector { x: 0.0, y: 90.0, z: 0.0 }, r: 40.0 }) };
    let o1: Object = Object { m: Material { base_color: Color {r: 1.0, g: 0.0, b: 0.2}, 
        refractive_index: 1.67, reflection_ratio: 0.8}, s: Box::new(Sphere { c: Vector { x: 20.0, y: 250.0, z: -14.0 }, r: 35.0 }) };
    let o2: Object = Object { m: Material { base_color: Color {r: 0.05, g: 0.076, b: 0.02}, 
        refractive_index: 2.67, reflection_ratio: 0.8}, s: Box::new(Plane { a: Vector { x: 20.0, y: 250.0, z: -90.0 }, n: Vector { x: 0.01, y: 0.01, z: 1.0 }.unit() }) };
    s.objects.push(o);
    s.objects.push(o1);
    s.objects.push(o2);
    s.render(6);
}
