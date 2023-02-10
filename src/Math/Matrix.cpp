/**
 * @file Matrix.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Provides implementation for the matrix class
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <algorithm>

#include "Matrix.h"

using namespace Tracer;

/**
 * @brief Construct a new Matrix:: Matrix object
 * 
 */
Matrix::Matrix()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			v[i][j] = 0;
}

/**
 * @brief Copy construct a new Matrix:: Matrix object
 * 
 * @param other 
 */
Matrix::Matrix(const Matrix& other)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->v[i][j] = other.v[i][j];
}

/**
 * @brief Matrix addition operator overload
 * 
 * @param other 
 * @return Matrix 
 */
Matrix Matrix::operator+(const Matrix& other) const
{
	Matrix m(other);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m.v[i][j] += this->v[i][j];

	return m;
}

/**
 * @brief Matrix subtraction operator overload
 * 
 * @param other 
 * @return Matrix 
 */
Matrix Matrix::operator-(const Matrix& other) const
{
	Matrix m(other);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m.v[i][j] -= this->v[i][j];

	return m;
}

/**
 * @brief Matrix multiplication operator overload
 * 
 * @param other 
 * @return Matrix 
 */
Matrix Matrix::operator*(const Matrix& other) const
{
	Matrix m;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			for (int element = 0; element < 3; element++)
				m.v[row][col] += this->v[row][element] * other.v[element][col];

	return m;
}

/**
 * @brief Matrix scalar multiplication operator overload
 * 
 * @param v 
 * @return Matrix 
 */
Matrix Matrix::operator*(const float v) const
{
	Matrix m(*this);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m.v[i][j] *= v;

	return m;
}

/**
 * @brief Matrix multiplication overload for operations on vectors
 * 
 * @param vec 
 * @return Vector 
 */
Vector Matrix::operator*(const Vector& vec) const
{
	float ve[3];

	for (int i = 0; i < 3; i++)
		ve[i] = vec.x * v[i][0] + vec.y * v[i][1] + vec.z * v[i][2];

	return Vector(ve[0], ve[1], ve[2]);
}

/**
 * @brief Copy assignment operator overload
 * 
 * @param other 
 * @return Matrix& 
 */
Matrix& Matrix::operator=(const Matrix& other)
{
	std::copy(&other.v[0][0], &other.v[0][0] + 9, &this->v[0][0]);

	return *this;
}

/**
 * @brief Matrix assignment addition operator overload
 * 
 * @param other 
 * @return Matrix& 
 */
Matrix& Matrix::operator+=(const Matrix& other)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->v[i][j] += other.v[i][j];

	return *this;
}

/**
 * @brief Matrix assignment subtraction operator overload
 * 
 * @param other 
 * @return Matrix& 
 */
Matrix& Matrix::operator-=(const Matrix& other)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->v[i][j] -= other.v[i][j];

	return *this;
}

/**
 * @brief Matrix assignment multiplication operator overload
 * 
 * @param other 
 * @return Matrix& 
 */
Matrix& Matrix::operator*=(const Matrix& other)
{
	Matrix m;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			for (int element = 0; element < 3; element++)
				m.v[row][col] += this->v[row][element] * other.v[element][col];

	*this = m;
	return *this;
}

/**
 * @brief Matrix assignment scalar multiplication operator overload
 * 
 * @param c 
 * @return Matrix& 
 */
Matrix& Matrix::operator*=(const float c)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->v[i][j] *= c;

	return *this;
}
