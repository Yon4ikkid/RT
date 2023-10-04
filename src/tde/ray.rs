use crate::math::Vector;

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