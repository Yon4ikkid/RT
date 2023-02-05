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

Ray::Ray() { }

Ray::Ray(const Vector& origin, const Vector& direction)
	: o(origin), d(direction) { }

Vector Ray::operator()(const float t) const
{
	return o + d * t;
}
