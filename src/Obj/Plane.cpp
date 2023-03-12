#include "Plane.h"
#include "../Math/Matrix.h"
#include <iostream>

using namespace Tracer;

Plane::Plane(Vector p, Vector n, const Material& material) : ISurface(material),  normal(n), p(p) { }

Vector Plane::get_normal(const Vector& p) const
{
    return this->normal;
}

Vector Plane::get_pivot() const
{
    return this->p;
}

bool Plane::intersect(const Ray& r, float& out)
{
    float div = normal * r.d;

    if (div == 0)
        return false;

    float t = (normal * (a - r.o)) / div;
    if (t < 0)
        return false;
    
    out = t;
    out.p = r(t);
    out.n = this->get_normal(out.p);
    out.m = this->get_material();

    return true;
}
