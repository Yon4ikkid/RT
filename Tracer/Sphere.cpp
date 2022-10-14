#include "Sphere.h"
#include "Ray.h"

using namespace Tracer;

Vector Sphere::getNormal(const Vector& p) const
{
	return (p - __c).unit();
}

Sphere::Sphere(const Vector& center, const float radius, const Material& material) 
	: __c(center), __r(radius), ISurface(material) { }

bool Sphere::intersect(const Ray& r, Intersection& out)
{
	float a, b, c, det;

	a = r.__d * r.__d;
	b = 2 * (r.__d * (r.__o - __c));
	c = r.__o * r.__o + __c * __c - __r * __r;
	det = b * b - 4 * a * c;

	if (det < 0)
		return false;

	float t = (-b - det) / (2 * a);
	out.__point = r(t);
	out.__normal = getNormal(out.__point);
	out.__m = getMaterial();

	return true;
}
