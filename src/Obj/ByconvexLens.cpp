#include "ByconvexLens.h"
#include <cmath>

using namespace Tracer;


Vector BiconvexLens::get_normal(const Vector &p) const
{
    if (p * this->sp1.get_centre() == this->r * this->r)
        return (p - this->sp1.get_centre()).unit();
    else
        return (p - this->sp1.get_centre()).unit();
}


BiconvexLens::BiconvexLens() { }


BiconvexLens::BiconvexLens(const Vector center, const Vector axis, const float curv_radius, const float sub_ratio)
    : c(center), r(curv_radius), a(sub_ratio)
{
    this->sp1 = Sphere(center + axis * curv_radius * (1.0f - sub_ratio), curv_radius);
    this->sp2 = Sphere(center - axis * curv_radius * (1.0f - sub_ratio), curv_radius);
}


std::optional<float> BiconvexLens::intersect(const Ray &r)
{
    auto op_t1 = this->sp1.intersect(r);
    auto op_t2 = this->sp2.intersect(r);

    if (!op_t1.has_value() && !op_t2.has_value())
        return std::nullopt;

    float t1 = op_t1.value();
    float t2 = op_t2.value();

    if ((r(t1) - this->c).norm() <= sqrtf(this->r * this->r - this->r * (1.0f - this->a)))
        return t1;

    if ((r(t2) - this->c).norm() <= sqrtf(this->r * this->r - this->r * (1.0f - this->a)))
        return t2;

    return std::nullopt;
}
