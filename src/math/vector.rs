use std::ops;
use std::cmp::Eq;

#[derive(Copy, Clone)]
pub struct Vector {
    pub x: f64,
    pub y: f64,
    pub z: f64,
}

impl Vector {
    pub fn new(x: f64, y: f64, z: f64) -> Vector {
        return Vector { x, y, z };
    }

    pub fn default() -> Vector {
        return Vector { x: 0.0, y: 0.0, z: 0.0 };
    }

    pub fn unit(self) -> Vector {
        let nr = self.norm();
        if nr == 0.0 {
            return Vector::default();
        }
        return self / nr;
    }

    pub fn norm(self) -> f64 {
        return f64::sqrt(self * self);
    }

    pub fn cross(self, other: Vector) -> Vector {
        return Vector {
            x: self.y * other.z - self.z * other.y,
            y: self.z * other.x - self.x * other.z,
            z: self.x * other.y - self.y * other.x
        }
    }

    pub fn ewm(self, other: Vector) -> Vector {
        return Vector {
            x: self.x * other.x,
            y: self.y * other.y,
            z: self.z * other.z,
        }
    }
}

impl ops::Add for Vector {
    type Output = Vector;

    fn add(self, rhs: Vector) -> Self::Output {
        return Vector { x: self.x + rhs.x, y: self.y + rhs.y, z: self.z + rhs.z };
    }
}

impl ops::Sub for Vector {
    type Output = Vector;

    fn sub(self, rhs: Vector) -> Self::Output {
        return Vector { x: self.x - rhs.x, y: self.y - rhs.y, z: self.z - rhs.z };
    }
}

impl PartialEq for Vector {
    fn eq(&self, rhs: &Self) -> bool {
        return self.x == rhs.x && self.y == rhs.y && self.z == rhs.z;
    }
}

impl Eq for Vector {}

impl ops::AddAssign for Vector {
    fn add_assign(&mut self, rhs: Vector) {
        self.x += rhs.x;
        self.y += rhs.y;
        self.z += rhs.z;
    }
}

impl ops::SubAssign for Vector {
    fn sub_assign(&mut self, rhs: Vector) {
        self.x -= rhs.x;
        self.y -= rhs.y;
        self.z -= rhs.z;
    }
}

impl ops::Neg for Vector {
    type Output = Vector;

    fn neg(self) -> Self::Output {
        return Vector { x: -self.x, y: -self.y, z: -self.z };
    }
}

impl ops::Div<f64> for Vector {
    type Output = Vector;

    fn div(self, rhs: f64) -> Self::Output {
        assert_ne!(rhs, 0.0);
        return Vector { x: self.x / rhs, y: self.y / rhs, z: self.z / rhs };
    }
}

impl ops::DivAssign<f64> for Vector {
    fn div_assign(&mut self, rhs: f64) {
        assert_ne!(rhs, 0.0);
        self.x /= rhs;
        self.y /= rhs;
        self.z /= rhs;
    }
}

impl ops::Mul<f64> for Vector {
    type Output = Vector;

    fn mul(self, rhs: f64) -> Vector {
        return Vector { x: self.x * rhs, y: self.y * rhs, z: self.z * rhs };
    }
}

impl ops::MulAssign<f64> for Vector {
    fn mul_assign(&mut self, rhs: f64) {
        self.x *= rhs;
        self.y *= rhs;
        self.z *= rhs;
    }
}

impl ops::Mul<Vector> for f64 {
    type Output = Vector;

    fn mul(self, rhs: Vector) -> Self::Output {
        return Vector { x: rhs.x * self, y: rhs.y * self, z: rhs.z * self };
    }
}

impl ops::Mul for Vector {
    type Output = f64;

    fn mul(self, rhs: Vector) -> Self::Output {
        return self.x * rhs.x + self.y * rhs.y + self.z * rhs.z;
    }
}