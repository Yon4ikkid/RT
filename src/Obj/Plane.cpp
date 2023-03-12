#include "Plane.h"
#include "../Math/Matrix.h"
#include <iostream>

using namespace Tracer;

// Plane::Plane(Vector a, Vector b, Vector c, const Material& material) : ISurface(material), ab(b - a), ac(c - a), a(a)
// {
//     Matrix A(2,2);
//     A.v[0][0] = ab.x;
//     A.v[0][1] = ab.y;
//     A.v[1][0] = ac.x;
//     A.v[1][1] = ac.y;

//     Matrix X(2,1);
//     X.v[0][0] = -ab.z;
//     X.v[1][0] = -ac.z;

//     Matrix N = A.inverse() * X;

//     this->normal = Vector(N.v[0][0], N.v[1][0], 1).unit();
// }

Plane::Plane(Vector p, Vector n, const Material& material) : ISurface(material),  normal(n), p(p) { }

Vector Plane::get_normal(const Vector& p) const
{
    return this->normal;
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

    // Vector p = r(t) - a;

    // Matrix A(2,2);
    // A.v[0][0] = ab.x;
    // A.v[0][1] = ac.x;
    // A.v[1][0] = ab.y;
    // A.v[1][1] = ac.y;

    // Matrix X(2,1);
    // X.v[0][0] = p.x;
    // X.v[1][0] = p.y;

    // Matrix C = A.inverse() * X;
    // float alpha = C.v[0][0], beta = C.v[1][0];
    // float s = alpha + beta;

    // if (std::abs(s) <= 1 && alpha >= 0 && beta >= 0)
    //     return true;

    return true;
}
