#include "Plane.h"
#include "../Math/Matrix.h"
#include <iostream>

using namespace Tracer;

Plane::Plane(Vector p, Vector n) : p(p), normal(n) { }

Plane::Plane() {}

Vector Plane::get_normal(const Vector& p) const
{
    return this->normal;
}

Vector Plane::get_pivot() const
{
    return this->p;
}

std::optional<float> Plane::intersect(const Ray& r)
{
    float div = normal * r.d;

    if (div == 0)
        return std::nullopt;

    float t = (normal * (this->p - r.o)) / div;

    return t;
}
