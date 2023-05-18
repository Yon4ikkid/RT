use crate::math::Vector;
use crate::rendering::{Intersectable, Color};

pub struct Ray {
    pub o: Vector,  // Origin
    pub d: Vector,  // Direction
    pub c: Color,   // Color intensities
    pub i: f64,     // Medium infraction index
}

impl Ray {
    pub fn new(o: Vector, d: Vector, c: Color, i: f64) -> Ray {
        return Ray { o, d, c, i };
    }

    pub fn get_point(&self, t: f64) -> Vector {
        return self.o + self.d * t;
    }

    pub fn refracted_direction(&self,  n: Vector, source_index: f64, target_index: f64) -> Vector {
        let mu: f64 = source_index / target_index;
        let reversed_d_n: Vector = (self.d * n) * n;
        let refracted_superficial: Vector = (self.d - reversed_d_n) / mu;
        let refracted_normal: Vector = reversed_d_n * (1.0 - refracted_superficial * refracted_superficial).sqrt();
        return refracted_superficial + refracted_normal;
    }

    pub fn reflected_direction(&self, n: Vector) -> Vector {
        return (((-self.d) * n) * n + self.d) * 2.0 - self.d;
    }
}

pub struct Sphere {
    pub c: Vector,
    pub r: f64
}

impl Intersectable for Sphere {
    fn intersect(&self, r: &Ray) -> (bool, Vector, Vector) {
        let  (a, b, c, det): (f64,f64,f64,f64);
        let l: Vector = r.o - self.c;
        a = r.d * r.d;
        b = 2.0 * (r.d * l);
        c = l * l - self.r * self.r;
        det = b * b - 4.0 * a * c;

        if det < 0.0 {
            return (false, Vector::default(), Vector::default());
        }

        let t: f64 = (-b - det.sqrt()) / (2.0 * a);
        if t < 0.1 {
            return (false, Vector::default(), Vector::default());
        }

        let p: Vector = r.get_point(t);
        return (true, p, (p - self.c).unit());
    }
}

pub struct Plane {
    pub a: Vector,
    pub n: Vector,
}

impl Intersectable for Plane {
    fn intersect(&self, r: &Ray) -> (bool, Vector, Vector) {
        let div: f64 = self.n * r.d;
        if div == 0.0 {
            return (false, Vector::default(), Vector::default());
        }

        let t: f64 = (self.n * (self.a - r.o)) / div;
        if t < 0.1 {
            return (false, Vector::default(), Vector::default());
        }

        return (true, r.get_point(t), self.n);
    }
}

pub struct Triangle {
    pub p: Plane,
    pub u: Vector,
    pub v: Vector,
}

pub struct Circle {

}

pub struct BiconvexLens {

}

pub struct OpenCylinder {

}

pub struct BiconcaveLens {
    
}

