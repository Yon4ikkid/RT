#include "ParticulateSphere.h"
#include <cmath>
#include <random>

using namespace Tracer;

static std::random_device rd;
static std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(-0.5, 0.5);

ParticulateSphere::ParticulateSphere()
{ // y = 4(x * m)^3 is our density across a segment

}


ParticulateSphere::ParticulateSphere(Vector center, float radius) : center(center), radius(radius) { }


std::optional<float> ParticulateSphere::intersect(const Ray& r)
{
    Vector oc = r.o - this->center;
    float om_length = oc * r.d;
    float l_squared = oc * oc - om_length * om_length;
    float radius_squared = this->radius * this->radius;

    if (l_squared > radius_squared)
        return std::nullopt;

    float m_ratio = std::sqrt(1 - l_squared / (this->radius * this->radius));

    float xm = dis(gen) * m_ratio;
    return om_length + 2.0f * (xm * xm * xm) * this->radius;
}


Vector ParticulateSphere::get_normal(const Vector& p) const
{
    return (p - this->center).unit();
}
