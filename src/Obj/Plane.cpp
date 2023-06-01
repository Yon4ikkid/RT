#include "Plane.h"
#include "../Math/Matrix.h"
#include <iostream>

using namespace Tracer;

Plane::Plane(Vector p, Vector n, const Material& material) : ISurface(material) , p(p), normal(n) { }

Plane::Plane() : ISurface(Material()) {}

Vector Plane::get_normal(const Vector& p) const
{
    return this->normal;
}

Vector Plane::get_pivot() const
{
    return this->p;
}

bool Plane::intersect(const Ray& r, Intersection& out)
{
    float div = normal * r.d;

    if (div == 0)
        return false;

    float t = (normal * (this->p - r.o)) / div;
    if (t < 0.01)
        return false;
    
    out.t = t;
    out.m = this->get_material();
    out.s = this;

    return true;
}
