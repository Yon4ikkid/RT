use crate::math::Vector;
use crate::rendering::Intersectable;

pub struct Ray {
    pub o: Vector,  // Origin
    pub d: Vector,  // Direction
    pub i: f64,     // Medium infraction index
}

impl Ray {
    pub fn new(o: Vector, d: Vector, i: f64) -> Ray {
        return Ray { o, d, i };
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
        return self.d - (self.d * n) * n * 2.0;
    }
}

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

pub struct Triangle {
    pub p: Plane,
    pub u: Vector,
    pub v: Vector,
}

pub struct Circle {
    pub p: Plane,
    pub r: f64,
}

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

pub struct OpenCylinder {

}

pub struct BiconcaveLens {
    
}

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
