use super::{Sphere, Ray};
use crate::math::Vector;
use crate::rendering::Intersectable;

pub struct BiconvexLens {
    sp1: Sphere,
    sp2: Sphere,
    pub c: Vector,
    pub r: f64,
    pub a: f64,
}

impl BiconvexLens {
    pub fn new(center: Vector, axis: Vector, curv_radius: f64, sub_ratio: f64) -> BiconvexLens {
        return BiconvexLens { 
            sp1: Sphere { c : center + axis * curv_radius * (1.0 - sub_ratio), r: curv_radius},
            sp2: Sphere { c: center - axis * curv_radius * (1.0 - sub_ratio), r: curv_radius},
            c: center,
            r: curv_radius,
            a: sub_ratio
        };
    }
}

impl Intersectable for BiconvexLens {
    fn intersect(&self, r: &Ray) -> Option<f64> {
        let op_t1 = self.sp1.intersect(r);
        let op_t2 = self.sp2.intersect(r);

        if op_t1.is_none() && op_t2.is_none() {
            return None;
        }

        let check = |p: Vector| {
            (p - self.c).norm() <= (self.r * self.r - self.r * (1.0 - self.a)).sqrt()
        };
        
        let t1 = op_t1.unwrap();
        let t2 = op_t2.unwrap();

        if check(r.get_point(t1)) {
            return Some(t1);
        }
        if check(r.get_point(t2)) {
            return Some(t2);
        }

        return None;
    }

    fn get_normal(&self, p: Vector) -> Vector {
        if p * self.sp1.c == self.r * self.r {
            return (p - self.sp1.c).unit();
        } else {
            return (p - self.sp2.c).unit();
        }
    }
}
