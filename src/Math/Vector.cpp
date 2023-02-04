#include <cmath>

#include "Vector.h"

using namespace Tracer;

// Default constructor: origin of coordinates
Vector::Vector() : x(0), y(0), z(0) { }

Vector::Vector(const float x, const float y, const float z)
	: x(x), y(y), z(z) { }

Vector::Vector(const Vector& other)
	: x(other.x), y(other.y), z(other.z) { }

bool Vector::operator==(const Vector& other) const
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

Vector Vector::operator+(const Vector& other) const
{
	return Vector(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector Vector::operator-(const Vector& other) const
{
	return Vector(this->x - other.x, this->y - other.y, this->z - other.z);
}

// Dot product
float Vector::operator*(const Vector& other) const
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector Vector::operator*(const float c) const
{
	return Vector(x * c, y * c, z * c);
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
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

Vector& Vector::operator+=(const Vector& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}

Vector& Vector::operator*=(const float c)
{
	this->x -= c;
	this->y -= c;
	this->z -= c;

	return *this;
}

std::ostream& Tracer::operator<<(std::ostream& os, const Vector& v)
{
	os << '(' << v.x << ',' << v.y << ',' << v.z << ')';
	return os;
}
