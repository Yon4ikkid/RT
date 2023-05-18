use math::Vector;
use rendering::{Object, Material, Color};
use tde::Sphere;

pub mod math;
pub mod tde;
pub mod rendering;
pub mod scene;

fn main() {
    let c: scene::Camera = scene::Camera::new(300, 300, 1000.0, math::Vector {x: 0.0, y: -600.0, z: 0.0}, 0.0, 0.0, 0.0);
    let mut s: scene::Scene = scene::Scene { ambient_light_color: rendering::Color { r: 0.0, g: 0.0, b: 0.1 }, camera: c, objects: std::vec::Vec::new() };
    let o: Object = Object { m: Material { base_color: Color {r: 0.9, g: 0.1, b: 0.1}, 
        refractive_index: 0.0, reflection_ratio: 0.0}, s: Box::new(Sphere { c: Vector { x: 0.0, y: 70.0, z: 0.0 }, r: 40.0 }) };
    s.objects.push(o);
    s.render(2);
}
