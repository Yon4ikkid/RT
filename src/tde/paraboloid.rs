use crate::math::Vector;
use crate::rendering::Intersectable;
use super::Ray;

pub struct Paraboloid {
    f: Vector,
    n: Vector,
    hfl: f64,
    l: f64,
}

impl Paraboloid { 
    pub fn new(apex: Vector, axis: Vector, fcl: f64, length: f64) -> Paraboloid {
        return Paraboloid {
            f: apex + fcl * axis,
            n: axis,
            hfl: fcl,
            l: length,
        };
    }
}

impl Intersectable for Paraboloid {
    fn intersect(&self, r: &Ray) -> Option<f64> {
        let k: Vector = r.o - self.f;
        let alpha: f64 = (r.d * self.n).powf(2.0) - r.d * r.d;
        let beta: f64 = 4.0 * self.hfl * (r.d * self.n) - 2.0 * (r.d * self.n) * (k * self.n) - 2.0 * (r.d * k);
        let gamma: f64 = 4.0 * self.hfl.powf(2.0) - 4.0 * self.hfl * (k * self.n) - k * k;
        let det: f64 = beta * beta - 4.0 * alpha * gamma;

        if det < 0.0 {
            return None;
        }

        let t1: f64 = (-beta - det.sqrt()) / (2.0 * alpha);
        if t1 < 0.01 {
            return None;
        }
        let p1: Vector = r.get_point(t1);
        if (p1 - self.f).norm() - self.hfl > self.l {
            return None;            
        }
        return Some(t1);
        
    }

    fn get_normal(&self, p: Vector) -> Vector {
        return (self.n + (p - self.f).unit()).unit();
    }
}
