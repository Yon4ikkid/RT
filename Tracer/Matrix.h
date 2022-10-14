#pragma once
#include "Vector.h"

namespace Tracer
{
	// A 3x3 matrix - a dependancy of some calculations.
	struct Matrix
	{
		float __v[3][3];

		Matrix();
		Matrix(const Matrix& other);

		Matrix operator+(const Matrix& other) const;
		Matrix operator-(const Matrix& other) const;
		Matrix operator*(const Matrix& other) const;
		Matrix operator*(const float v) const;
		Vector operator*(const Vector& vec) const;

		Matrix& operator=(const Matrix& other);
		Matrix& operator+=(const Matrix& other);
		Matrix& operator-=(const Matrix& other);
		Matrix& operator*=(const Matrix& other);
		Matrix& operator*=(const float c);
	};
}
