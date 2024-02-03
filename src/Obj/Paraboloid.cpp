#include "Paraboloid.h"
#include <cmath>

using namespace Tracer;

Vector Paraboloid::get_normal(const Vector& p) const
{
    return (this->axis + (p - this->focus).unit()).unit();
}


Paraboloid::Paraboloid() { }


Paraboloid::Paraboloid(Vector apex, Vector n, float focal_length, float length) 
    : axis(n), focus(apex + n * focal_length), focal_length(focal_length), length(length) { }


std::optional<float> Paraboloid::intersect(const Ray& r)
{
    Vector k = r.o - this->focus;
    float alpha = (r.d * this->axis) * (r.d * this->axis) - r.d * r.d;
    float beta = 4.0f * this->focal_length * (r.d * this->axis) - 2.0f * (r.d * this->axis) * (k * this->axis) - 2.0f * (r.d * k);
    float gamma = 4.0f * this->focal_length * this->focal_length - 4.0f * this->focal_length * (k * this->axis) - k * k;
    float det = beta * beta - 4.0f * alpha * gamma;

    if (det < 0)
        return std::nullopt;

    float t1 = (-beta - sqrtf(det)) / (2.0f * alpha);
    Vector p1 = r(t1);
    if ((p1 - this->focus).norm() - this->focal_length > this->length)
        return std::nullopt;

    return t1;
}
