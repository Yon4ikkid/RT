use std::{result::Result, option::Option};

pub struct Interval {
    a: f64,
    b: f64,
}

impl Interval {
    pub fn new(a: f64, b: f64) -> Option<Interval> {
        if a >= b {
            return None;
        } else {
            return Some(Interval{a, b});
        }
    }

    pub fn whole_interval() -> Interval {
        return Interval::new(f64::MIN, f64::MAX).unwrap();
    }

    pub fn test_interval_intersection(self, i: Interval) -> bool {
        return self.intersect_interval(Some(i)).is_some();
    }

    pub fn test_f64_intersection(self, f: f64) -> bool {
        return f >= self.a && f <= self.b;
    }

    pub fn intersect_interval(self, i: Option<Interval>) -> Option<Interval> {
        if i.is_some() {
            let uni: Interval = i.unwrap();
            return Interval::new(self.a.max(uni.a), self.b.min(uni.b));
        } else {
            return None;
        }
    }
}
