use crate::math::Interval;

pub struct AABB {
    x: Interval,
    y: Interval,
    z: Interval,
}

impl AABB {
    pub fn new(xi: Interval, yi: Interval, zi: Interval) -> AABB {
        return AABB {x: xi, y: yi, z: zi};
    }


    pub fn intersect_ray(&self, r: &Ray) -> bool {
        let generate_validation_interval = |direction_component: f64, origin_component: f64, i: Interval| -> Interval {
            if (direction_component == 0) {
                if (i.test_f64_intersection(origin_component)) {
                    return Interval::whole_interval();
                }
            } else {
                return Interval::new((i.a - origin_component) / direction_component, (i.b - origin_component) / direction_component);
            }
        };
        
        return generate_validation_interval(r.d.x, r.o.x, self.x).intersect_interval(generate_validation_interval(r.d.y, r.o.y, self.y).intersect_interval(generate_validation_interval(r.d.z, r.o.z, self.z))).is_some();
    }
}
