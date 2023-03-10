#include "Plane.h"
#include "../Math/Matrix.h"

using namespace Tracer;

Plane::Plane(Vector a, Vector b, Vector c, const Material& material) : ISurface(material), ab(b - a), ac(c - a)
{
    Matrix A(2,2);
    A.v[0][0] = ab.x;
    A.v[0][1] = ab.y;
    A.v[1][0] = ac.x;
    A.v[1][1] = ac.y;

    Matrix X(2,1);
    X.v[0][0] = -ab.z;
    X.v[1][0] = -ac.z;

    Matrix N = A.inverse() * X;

    this->normal = Vector(N.v[0][0], N.v[1][0], 1);
}

Vector Plane::get_normal(const Vector& p) const
{
    return this->normal;
}

bool Plane::intersect(const Ray& r, float& out)
{
    // Check barycentric coordinates
    return false;
}
