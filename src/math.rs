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
        return self / self.norm();
    }

    pub fn norm(self) -> f64 {
        return f64::sqrt(self * self);
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
        if rhs == 0.0 {
            panic!("Vector division by zero!");
        }
        return Vector { x: self.x / rhs, y: self.y / rhs, z: self.z / rhs };
    }
}

impl ops::DivAssign<f64> for Vector {
    fn div_assign(&mut self, rhs: f64) {
        if rhs == 0.0 {
            panic!("Vector division by zero!");
        }
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

#[derive(Copy, Clone)]
pub struct Matrix {
    pub values: [[f64; 3];3],
    width: usize,
    height: usize,
}

impl Matrix {
    pub fn new(width: usize, height: usize) -> Matrix {
        return Matrix { values: [[0.0; 3]; 3], width, height };
    }

    pub fn inverse(self) -> Result<Matrix, i32> {
        if self.width != 2 || self.height != 2 {
            panic!("Trying to inverse a non 2x2 matrix!");
        }

        let mut m: Matrix = Matrix::new(2,2);

        let (a,b,c,d): (f64,f64,f64,f64) = (self.values[0][0], self.values[0][1], self.values[1][0], self.values[1][1]);
        let determinant: f64 = a * d - b * c;
        if determinant == 0.0 {
            return Err(0);
        }

        m.values[0][0] = d;
        m.values[0][1] = -b;
        m.values[1][0] = -c;
        m.values[1][1] = a;

        return Ok(m);
    }
}

impl ops::Add for Matrix { 
    type Output = Matrix;

    fn add(self, rhs: Matrix) -> Self::Output {
        let mut m: Matrix = Matrix::new(self.width, self.height); 
        for i in 0..self.height {
            for j in 0..self.width {
                m.values[i][j] = self.values[i][j] + rhs.values[i][j];
            }
        }
        return m;
    }
}

impl ops::AddAssign for Matrix {
    fn add_assign(&mut self, rhs: Matrix) {
        for i in 0..self.height {
            for j in 0..self.width {
                self.values[i][j] += rhs.values[i][j];
            }
        }
    }
}

impl ops::Sub for Matrix {
    type Output = Matrix;

    fn sub(self, rhs: Matrix) -> Self::Output {
        let mut m: Matrix = Matrix::new(self.width, self.height); 
        for i in 0..self.height {
            for j in 0..self.width {
                m.values[i][j] = self.values[i][j] - rhs.values[i][j];
            }
        }
        return m;
    }
}

impl ops::SubAssign for Matrix {
    fn sub_assign(&mut self, rhs: Matrix) {
        for i in 0..self.height {
            for j in 0..self.width {
                self.values[i][j] -= rhs.values[i][j];
            }
        }
    }
}

impl ops::Mul<f64> for Matrix {
    type Output = Matrix;

    fn mul(self, rhs: f64) -> Self::Output {
        let mut m: Matrix = Matrix::new(self.width, self.height); 
        for i in 0..self.height {
            for j in 0..self.width {
                m.values[i][j] = self.values[i][j] * rhs;
            }
        }
        return m;
    }
}

impl ops::Mul<Matrix> for f64 {
    type Output = Matrix;

    fn mul(self, rhs: Matrix) -> Self::Output {
        let mut m: Matrix = Matrix::new(rhs.width, rhs.height); 
        for i in 0..rhs.height {
            for j in 0..rhs.width {
                m.values[i][j] = rhs.values[i][j] * self;
            }
        }
        return m;
    }
}

impl ops::MulAssign<f64> for Matrix {
    fn mul_assign(&mut self, rhs: f64) {
        for i in 0..self.height {
            for j in 0..self.width {
                self.values[i][j] *= rhs;
            }
        }
    }
}

impl ops::Mul for Matrix {
    type Output = Matrix;

    fn mul(self, rhs: Matrix) -> Self::Output {
        if self.width != rhs.height {
            panic!("Matrix multiplication size mismatch!");
        }

        let mut m: Matrix = Matrix::new(self.height, rhs.width);

        for i in 0..self.height {
            for j in 0..rhs.width {
                for k in 0..self.width {
                    m.values[i][j] += self.values[i][k] * rhs.values[k][j];
                }
            }
        }

        return m;
    }
}

impl ops::Mul<Vector> for Matrix {
    type Output = Vector;

    fn mul(self, rhs: Vector) -> Self::Output {
        let mut vecvals: [f64; 3] = [0.0; 3];
        for i in 0..3 {
            vecvals[i] = self.values[i][0] * rhs.x + self.values[i][1] * rhs.y + self.values[i][2] * rhs.z;
        }
        return Vector::new(vecvals[0],vecvals[1],vecvals[2]);
    }
}

impl ops::Neg for Matrix {
    type Output = Matrix;

    fn neg(self) -> Self::Output {
        let mut m: Matrix = Matrix::new(self.width, self.height);
        for i in 0..self.height {
            for j in 0..self.width {
                m.values[i][j] = -self.values[i][j];
            }
        }

        return m;
    }
}
