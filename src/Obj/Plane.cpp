#include "Plane.h"

using namespace Tracer;

Plane::Plane(Vector a, Vector b, Vector c, const Material& material) : ISurface(material), ab(b - a), ac(c - a) { }

Vector Plane::get_normal(const Vector& p) const
{
    return this->normal;
}

bool Plane::intersect(const Ray& r, float& out)
{
    // Check barycentric coordinates
    return false;
}
