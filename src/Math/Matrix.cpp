#include <algorithm>

#include "Matrix.h"

using namespace Tracer;

Matrix::Matrix()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			v[i][j] = 0;
}

Matrix::Matrix(const Matrix& other)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->v[i][j] = other.v[i][j];
}

Matrix Tracer::Matrix::operator+(const Matrix& other) const
{
	Matrix m(other);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m.v[i][j] += this->v[i][j];

	return m;
}

Matrix Tracer::Matrix::operator-(const Matrix& other) const
{
	Matrix m(other);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m.v[i][j] -= this->v[i][j];

	return m;
}

Matrix Tracer::Matrix::operator*(const Matrix& other) const
{
	Matrix m;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			for (int element = 0; element < 3; element++)
				m.v[row][col] += this->v[row][element] * other.v[element][col];

	return m;
}

Matrix Tracer::Matrix::operator*(const float v) const
{
	Matrix m(*this);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m.v[i][j] *= v;

	return m;
}

Vector Tracer::Matrix::operator*(const Vector& vec) const
{
	float ve[3];

	for (int i = 0; i < 3; i++)
		ve[i] = vec[0] * v[i][0] + vec[1] * v[i][1] + vec[2] * v[i][2];

	return Vector(ve[0], ve[1], ve[2]);
}

Matrix& Tracer::Matrix::operator=(const Matrix& other)
{
	std::copy(&other.v[0][0], &other.v[0][0] + 9, &this->v[0][0]);

	return *this;
}

Matrix& Tracer::Matrix::operator+=(const Matrix& other)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->v[i][j] += other.v[i][j];

	return *this;
}

Matrix& Tracer::Matrix::operator-=(const Matrix& other)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->v[i][j] -= other.v[i][j];

	return *this;
}

Matrix& Tracer::Matrix::operator*=(const Matrix& other)
{
	Matrix m;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			for (int element = 0; element < 3; element++)
				m.v[row][col] += this->v[row][element] * other.v[element][col];

	*this = m;
	return *this;
}

Matrix& Tracer::Matrix::operator*=(const float c)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->v[i][j] *= c;

	return *this;
}
