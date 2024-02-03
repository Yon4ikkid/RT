#include "Circle.h"

using namespace Tracer;

Circle::Circle(const Vector a, const Vector n, const float r) : plane(a,n), radius(r) { }

std::optional<float> Circle::intersect(const Ray& r)
{
    auto t_opt = this->plane.intersect(r);
    if (!t_opt.has_value())
        return t_opt;

    if ((r(t_opt.value()) - this->plane.get_pivot()).norm() <= this->radius)
        return t_opt;
    
    return std::nullopt;
}
