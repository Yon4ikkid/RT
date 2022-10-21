#include "Ray.h"

using namespace Tracer;

Ray::Ray() { }

Ray::Ray(const Vector& origin, const Vector& direction)
	: o(origin), d(direction) { }

Vector Ray::operator()(const float t) const
{
	return o + d * t;
}
