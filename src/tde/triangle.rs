use super::Plane;
use crate::math::Vector;

pub struct Triangle {
    pub p: Plane,
    pub u: Vector,
    pub v: Vector,
}