#include "Circle.h"

using namespace Tracer;

Circle::Circle(const Vector a, const Vector n, const float r, const Material& material) : plane(a,n,material), radius(r) { }

bool Circle::intersect(const Ray& r, Intersection& out)
{
    if (!this->plane.intersect(r, out))
        return false;

    if ((r(out.t) - this->plane.get_pivot()).norm() <= this->radius)
        return true;
    
    return false;
}
