/**
 * @file Ray.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Provides implementation for the Ray struct
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Ray.h"

using namespace Tracer;

/**
 * @brief Construct a new Ray:: Ray object
 * 
 */
Ray::Ray() { }

/**
 * @brief Construct a new Ray:: Ray object
 * 
 * @param origin - the origin of the ray
 * @param direction - the direction vector of the ray
 */
Ray::Ray(const Vector& origin, const Vector& direction)
	: o(origin), d(direction) { }

/**
 * @brief Calculates a point on the ray
 * 
 * @param t - direction multiplier
 * @return Vector - point on ray at o + d * t
 */
Vector Ray::operator()(const float t) const
{
	return o + d * t;
}

std::ostream& Tracer::operator<<(std::ostream& os, const Ray& r)
{
	os << "O: " << r.o << " D: " << r.d << std::endl;
}
