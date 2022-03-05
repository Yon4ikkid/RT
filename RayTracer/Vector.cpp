#include "Vector.h"
#include <exception>

Vector::Vector(const float x, const float y, const float z)
{
	__xyz[0] = x;
	__xyz[1] = y;
	__xyz[2] = z;
}

Vector::Vector() : Vector(0, 0, 0) { }

Vector::Vector(const float xyz[3]) : Vector(xyz[0], xyz[1], xyz[2]) { }

Vector Vector::operator+(const Vector& other) const
{
	return Vector(
		__xyz[0] + other.__xyz[0],
		__xyz[1] + other.__xyz[1],
		__xyz[2] + other.__xyz[2]
	);
}

Vector Vector::operator-(const Vector& other) const
{
	return Vector(
		__xyz[0] - other.__xyz[0],
		__xyz[1] - other.__xyz[1],
		__xyz[2] - other.__xyz[2]
	);
}

float Vector::operator*(const Vector& other) const
{
	return	__xyz[0] * other.__xyz[0] +
			__xyz[1] * other.__xyz[1] +
			__xyz[2] * other.__xyz[2];
}

Vector Vector::operator*(const float& val) const
{
	return Vector(
		__xyz[0] * val,
		__xyz[1] * val,
		__xyz[2] * val
	);
}

Vector Vector::operator/(const float& val) const
{
	if (val == 0) throw std::exception("Error: Division by zero");
	return (*this) * (1 / val);
}

Vector& Vector::operator+=(const Vector& other)
{
	__xyz[0] += other.__xyz[0];
	__xyz[1] += other.__xyz[1];
	__xyz[2] += other.__xyz[2];

	return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
	__xyz[0] -= other.__xyz[0];
	__xyz[1] -= other.__xyz[1];
	__xyz[2] -= other.__xyz[2];

	return *this;
}

Vector& Vector::operator*=(const float& val)
{
	__xyz[0] *= val;
	__xyz[1] *= val;
	__xyz[2] *= val;

	return *this;
}

Vector& Vector::operator/=(const float& val)
{
	__xyz[0] /= val;
	__xyz[1] /= val;
	__xyz[2] /= val;

	return *this;
}
