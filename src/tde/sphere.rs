use crate::rendering::Intersectable;
use crate::math::Vector;
use super::Ray;

pub struct Sphere {
    pub c: Vector,
    pub r: f64
}

impl Intersectable for Sphere {
    fn intersect(&self, r: &Ray) -> Option<f64> {
        let  (a, b, c, det): (f64,f64,f64,f64);
        let l: Vector = r.o - self.c;
        a = r.d * r.d;
        b = 2.0 * (r.d * l);
        c = l * l - self.r * self.r;
        det = b * b - 4.0 * a * c;

        if det < 0.0 {
            return None;
        }

        let t: f64 = (-b - det.sqrt()) / (2.0 * a);
        if t < 0.01 {
            return None;
        }

        return Some(t);
    }

    fn get_normal(&self, p: Vector) -> Vector {
        return (p - self.c).unit();
    }
}
