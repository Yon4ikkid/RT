#include <cmath>

#include "Vector.h"

using namespace Tracer;

// Default constructor: origin of coordinates
Vector::Vector() : __x(0), __y(0), __z(0) { }

Vector::Vector(const float x, const float y, const float z)
	: __x(x), __y(y), __z(z) { }

Vector::Vector(const Vector& other)
	: __x(other.__x), __y(other.__y), __z(other.__z) { }

bool Vector::operator==(const Vector& other) const
{
	return this->__x == other.__x && this->__y == other.__y && this->__z == other.__z;
}

Vector Vector::operator+(const Vector& other) const
{
	return Vector(this->__x + other.__x, this->__y + other.__y, this->__z + other.__z);
}

Vector Vector::operator-(const Vector& other) const
{
	return Vector(this->__x - other.__x, this->__y - other.__y, this->__z - other.__z);
}

// Dot product
float Vector::operator*(const Vector& other) const
{
	return this->__x * other.__x + this->__y * other.__y + this->__z * other.__z;
}

Vector Vector::operator*(const float c) const
{
	return Vector(__x * c, __y * c, __z * c);
}

Vector Vector::unit() const
{
	return *this * (1 / norm());
}

float Vector::norm() const
{
	return sqrtf((*this) * (*this));
}

// Copy operator
Vector& Vector::operator=(const Vector& other)
{
	this->__x = other.__x;
	this->__y = other.__y;
	this->__z = other.__z;

	return *this;
}

Vector& Vector::operator+=(const Vector& other)
{
	this->__x += other.__x;
	this->__y += other.__y;
	this->__z += other.__z;

	return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
	this->__x -= other.__x;
	this->__y -= other.__y;
	this->__z -= other.__z;

	return *this;
}

Vector& Vector::operator*=(const float c)
{
	this->__x -= c;
	this->__y -= c;
	this->__z -= c;

	return *this;
}

std::ostream& Tracer::operator<<(std::ostream& os, const Vector& v)
{
	os << '(' << v.__x << ',' << v.__y << ',' << v.__z << ')';
	return os;
}
