#include "Ray.h"

using namespace Tracer;

Ray::Ray() { }

Ray::Ray(const Vector& origin, const Vector& direction)
	: __o(origin), __d(direction) { }

Vector Ray::operator()(const float t) const
{
	return __o + __d * t;
}
