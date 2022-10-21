#pragma once
#include <iostream>

namespace Tracer
{
	// A member of the affine space.
	// The vector is a triplet of float values representing the coordinates of its
	//	endpoint.
	struct Vector
	{
		float x;
		float y;
		float z;

		// Constructors
		Vector();
		Vector(const float ix, const float iy, const float iz);
		Vector(const Vector& other);

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
