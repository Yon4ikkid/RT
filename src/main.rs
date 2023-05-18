use math::Vector;
use rendering::{Object, Material, Color, PointLight, DirectionalLight};
use tde::Sphere;

pub mod math;
pub mod tde;
pub mod rendering;
pub mod scene;

fn main() {
    let c: scene::Camera = scene::Camera::new(300, 300, 1000.0, math::Vector {x: 0.0, y: -600.0, z: 0.0}, 0.0, 0.0, 0.0);
    let mut s: scene::Scene = scene::Scene { ambient_light_color: rendering::Color { r: 0.01, g: 0.02, b: 0.1 }, camera: c, objects: std::vec::Vec::new(),
                                            //  lightsource: Box::new(PointLight {c: Color { r: 1.0, g: 0.5, b: 0.5 } , o: Vector { x: -120.0, y: 40.0, z: 130.0 }, d: 350.0 }) };
                                            lightsource: Box::new(DirectionalLight {c: Color { r: 1.0, g: 0.1, b: 0.1 } , d: Vector { x: 1.0, y: 1.0, z: -1.0 }.unit()}) };
    let o: Object = Object { m: Material { base_color: Color {r: 1.0, g: 0.1, b: 0.1}, 
        refractive_index: 0.0, reflection_ratio: 0.0}, s: Box::new(Sphere { c: Vector { x: 0.0, y: 90.0, z: 0.0 }, r: 40.0 }) };
    s.objects.push(o);
    s.render(2);
}
