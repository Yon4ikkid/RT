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

    pub fn refract(&self,  n: Vector, source_index: f64, target_index: f64) -> Ray {

    }

    pub fn reflect(&self, n: Vector, source_index: f64, target_index: f64) -> Ray {

    }
}

pub struct Sphere {
    pub c: Vector,
    pub r: f64
}

impl Intersectable for Sphere {
    fn intersect(&self, r: &Ray) -> (bool, Vector,Vector) {
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
        if t < 0.0 {
            return (false, Vector::default(), Vector::default());
        }

        let p: Vector = r.get_point(t);
        return (true, p, (p - self.c).unit());
    }
}

pub struct Plane {

}

pub struct Triangle {

}

pub struct Circle {

}

pub struct BiconvexLens {

}

pub struct OpenCylinder {

}

pub struct BiconcaveLens {
    
}

