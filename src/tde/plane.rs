use crate::rendering::Intersectable;
use crate::math::Vector;
use super::Ray;

pub struct Plane {
    pub a: Vector,
    pub n: Vector,
}

impl Intersectable for Plane {
    fn intersect(&self, r: &Ray) -> Option<f64> {
        let div: f64 = self.n * r.d;
        if div == 0.0 {
            return None;
        }

        let t: f64 = (self.n * (self.a - r.o)) / div;
        if t < 0.01 {
            return None;
        }

        return Some(t);
    }

    fn get_normal(&self, _p: Vector) -> Vector {
        return self.n;
    }
}
