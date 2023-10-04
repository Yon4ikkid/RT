use std::ops;
use super::Vector;

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
        assert!(self.width == 2 && self.height == 2);

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
