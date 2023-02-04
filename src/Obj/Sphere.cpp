#include "Sphere.h"
#include "../Render/Ray.h"

using namespace Tracer;

Vector Sphere::get_normal(const Vector& p) const
{
	return (p - centre).unit();
}

Sphere::Sphere(const Vector& center, const float radius, const Material& material) 
	: centre(center), radius(radius), ISurface(material) { }

bool Sphere::intersect(const Ray& r, Vector& out)
{
	float a, b, c, det;
	Vector l = r.o - centre;

	a = r.d * r.d;
	b =  2 * (r.d * l);
	c = l * l - radius * radius;
	det = b * b - 4 * a * c;

	if (det < 0)
		return false;

	float t = (-b - det) / (2 * a);
	out = r(t);

	return true;
}
