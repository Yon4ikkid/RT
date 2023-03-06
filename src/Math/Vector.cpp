/**
 * @file Vector.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Provides implementation for the Vector class and the derived expressions
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <cmath>

#include "Vector.h"

using namespace Tracer;

/**
 * @brief Construct a new Vector:: Vector object
 * 
 */
Vector::Vector() : x(0), y(0), z(0) { }

/**
 * @brief Construct a new Vector:: Vector object
 * 
 * @param x 
 * @param y 
 * @param z 
 */
Vector::Vector(const float x, const float y, const float z) : x(x), y(y), z(z) { }

/**
 * @brief Copy construct a new Vector:: Vector object
 * 
 * @param other 
 */
Vector::Vector(const Vector& other) : Vector(other.x, other.y, other.z) { }

/**
 * @brief Checks equality of two vectors by coordinates
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Vector::operator==(const Vector& other) const
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

/**
 * @brief Vector addition operator overload
 * 
 * @param other 
 * @return Vector 
 */
Vector Vector::operator+(const Vector& other) const
{
	return Vector(this->x + other.x, this->y + other.y, this->z + other.z);
}

/**
 * @brief Vector subtraction operator overload
 * 
 * @param other 
 * @return Vector 
 */
Vector Vector::operator-(const Vector& other) const
{
	return Vector(this->x - other.x, this->y - other.y, this->z - other.z);
}

/**
 * @brief Vector dot product operator overload
 * 
 * @param other 
 * @return float 
 */
float Vector::operator*(const Vector& other) const
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

/**
 * @brief Vector scalar multiplication operator overload
 * 
 * @param c 
 * @return Vector 
 */
Vector Vector::operator*(const float c) const
{
	return Vector(x * c, y * c, z * c);
}

Vector Vector::operator-() const
{
	return Vector(-x, -y, -z);
}

/**
 * @brief Returns the unit vector collinear with the original
 * 
 * @return Vector 
 */
Vector Vector::unit() const
{
	return *this * (1.0f / norm());
}

/**
 * @brief Returns the length of the vector
 * 
 * @return float 
 */
float Vector::norm() const
{
	return sqrtf((*this) * (*this));
}

/**
 * @brief Copy assignment operator overload
 * 
 * @param other 
 * @return Vector& 
 */
Vector& Vector::operator=(const Vector& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

/**
 * @brief Vector assignment addition operator overload
 * 
 * @param other 
 * @return Vector& 
 */
Vector& Vector::operator+=(const Vector& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

/**
 * @brief Vector assignment subtraction operator overload
 * 
 * @param other 
 * @return Vector& 
 */
Vector& Vector::operator-=(const Vector& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}

/**
 * @brief Vector assignment scalar multiplication operator overload
 * 
 * @param c 
 * @return Vector& 
 */
Vector& Vector::operator*=(const float c)
{
	this->x *= c;
	this->y *= c;
	this->z *= c;

	return *this;
}

/**
 * @brief Stream insertion operator
 * 
 * @param os - output stream
 * @param v - vector
 * @return std::ostream& 
 */
std::ostream& Tracer::operator<<(std::ostream& os, const Vector& v)
{
	os << '(' << v.x << ',' << v.y << ',' << v.z << ')';
	return os;
}
