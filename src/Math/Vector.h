#pragma once
#include <iostream>

namespace Tracer
{
	template <typename T>
	struct VectorExpression {
		float operator[](const size_t i) const;
	};

	struct Vector : public VectorExpression<Vector>
	{
		float values[3];
		float x,y,z;

		// Constructors
		Vector();
		Vector(const float ix, const float iy, const float iz);
		Vector(const Vector& other);

		template <typename T>
		Vector(const VectorExpression<T>& expression);

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
