/**
 * @file Vector.h
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Defines the Vector class along with the expressions
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <iostream>

namespace Tracer
{
	struct Vector
	{
		float x,y,z;

		// Constructors
		Vector();
		Vector(const float ix, const float iy, const float iz);
		Vector(const Vector& other);

		float operator[](const size_t i) const;
		float& operator[](const size_t i);

		// Operator overload
		bool operator==(const Vector& other) const;
		Vector operator+(const Vector& other) const;
		Vector operator-(const Vector& other) const;
		float operator*(const Vector& other) const;
		Vector operator*(const float c) const;
		Vector unit() const;
		float norm() const;

		Vector& operator=(const Vector& other);
		Vector& operator+=(const Vector& other);
		Vector& operator-=(const Vector& other);
		Vector& operator*=(const float c);

		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
