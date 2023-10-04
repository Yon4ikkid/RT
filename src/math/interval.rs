use std::result::Result;

pub struct Interval {
    a: f64,
    b: f64,
}

impl Interval {
    pub fn new(a: f64, b: f64) -> Result<Interval, i32> {
        if a >= b {
            return Err(23);
        } else {
            return Ok(Interval{a, b});
        }
        
    }

    pub fn test_interval_intersection(self, i: Interval) -> bool {
        return self.intersect_interval(i).is_ok();
    }

    pub fn test_f64_intersection(self, f: f64) -> bool {
        return f >= self.a && f <= self.b;
    }

    pub fn intersect_interval(self, i: Interval) -> Result<Interval, i32> {
        return Interval::new(self.a.max(i.a), self.b.min(i.b));
    
    }
}
