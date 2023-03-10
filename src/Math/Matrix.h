/**
 * @file Matrix.h
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Defines the Matrix class
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "Vector.h"

namespace Tracer
{
	// A 3x3 matrix - a dependancy of some calculations.
	struct Matrix
	{
		float v[3][3];
		unsigned int width, height;

		Matrix();
		Matrix(unsigned int w, unsigned int h);
		Matrix(const Matrix& other);

		Matrix operator+(const Matrix& other) const;
		Matrix operator-(const Matrix& other) const;
		Matrix operator*(const Matrix& other) const;
		Matrix operator*(const float v) const;
		Vector operator*(const Vector& vec) const;
		Matrix inverse() const;

		Matrix& operator=(const Matrix& other);
		Matrix& operator+=(const Matrix& other);
		Matrix& operator-=(const Matrix& other);
		Matrix& operator*=(const Matrix& other);
		Matrix& operator*=(const float c);
	};
}
