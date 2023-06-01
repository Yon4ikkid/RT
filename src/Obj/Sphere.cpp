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

Sphere::Sphere(const Vector& center, const float radius, const Material& material) 
	: centre(center), radius(radius), ISurface(material) { }

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

/**
 * @brief Checks for intersection with a given ray
 * 
 * @param r - target ray
 * @param out - output vector (assigned if result was true)
 * @return true - does intersect
 * @return false - does not intersect
 */
bool Sphere::intersect(const Ray& r, Intersection& out)
{
	float a, b, c, det;
	Vector l = r.o - centre;
	a = r.d * r.d;
	b =  2 * (r.d * l);
	c = l * l - radius * radius;
	det = b * b - 4 * a * c;

	if (det < 0)
		return false;

	float t = (-b - sqrtf(det)) / (2 * a);
	if (t < 0.01)
		return false;

	out.t = t;
	out.m = this->get_material();
	out.s = this;

	return true;
}
