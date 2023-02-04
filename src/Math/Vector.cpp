#include <cmath>

#include "Vector.h"

using namespace Tracer;

// Default constructor: origin of coordinates
Vector::Vector() {
	for (int i = 0; i < 3; ++i)
		this->values[i] = 0;
}

Vector::Vector(const float x, const float y, const float z) {
	this->values[0] = x;
	this->values[1] = y;
	this->values[2] = z;
}

Vector::Vector(const Vector& other) {
	for (int i = 0; i < 3; ++i)
		this->values[i] = other.values[i];
}

bool Vector::operator==(const Vector& other) const {
	for (int i = 0; i < 3; ++i)
		if (this->values[i] != other.values[i])
			return false;
	return true;
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
