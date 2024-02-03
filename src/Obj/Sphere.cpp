/**
 * @file Sphere.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Provides implementation for the Sphere class
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Sphere.h"
#include "../Render/Ray.h"
#include <cmath>

using namespace Tracer;

Sphere::Sphere() { }

Sphere::Sphere(const Vector& center, const float radius) 
	: centre(center), radius(radius) { }

/**
 * @brief Returns the normal of the sphere at a given surface point
 * 
 * @param p 
 * @return Vector 
 */
Vector Sphere::get_normal(const Vector& p) const
{
	return (p - centre).unit();
}


Vector Sphere::get_centre() const
{
	return this->centre;
}


std::optional<float> Sphere::intersect(const Ray& r)
{
	float a, b, c, det;
	Vector l = r.o - centre;
	a = r.d * r.d;
	b =  2 * (r.d * l);
	c = l * l - radius * radius;
	det = b * b - 4 * a * c;

	if (det < 0)
		return std::nullopt;

	float t = (-b - sqrtf(det)) / (2 * a);

	return t;
}
