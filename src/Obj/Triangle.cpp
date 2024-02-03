#include "Triangle.h"
#include "Plane.h"
#include "../Math/Matrix.h"

using namespace Tracer;

Triangle::Triangle(Vector a, Vector b, Vector c)
{
    // Matrix solution
    // Matrix A(2,2);
    // A.v[0][0] = this->u.x;
    // A.v[0][1] = this->u.y;
    // A.v[1][0] = this->v.x;
    // A.v[1][1] = this->v.y;

    // Matrix X(2,1);
    // X.v[0][0] = -this->u.z;
    // X.v[1][0] = -this->v.z;

    // Matrix N = A.inverse() * X;

    // Cross
    this->u = b - a;
    this->v = c - a;
    Vector n = this->u.cross(this->v);

    this->p = Plane(a, n.unit());
}

std::optional<float> Triangle::intersect(const Ray& r)
{
    auto t_opt = this->p.intersect(r);
    
    if (!t_opt.has_value())
        return t_opt;

    float t = t_opt.value();
    Vector p = r(t) - this->p.get_pivot();

    Matrix A(2,2);
    A.v[0][0] = this->u.x;
    A.v[0][1] = this->v.x;
    A.v[1][0] = this->u.y;
    A.v[1][1] = this->v.y;

    Matrix X(2,1);
    X.v[0][0] = p.x;
    X.v[1][0] = p.y;

    Matrix C = A.inverse() * X;
    float alpha = C.v[0][0], beta = C.v[1][0];
    float s = alpha + beta;

    if (std::abs(s) <= 1 && alpha >= 0 && beta >= 0)
        return t;
    
    return std::nullopt;
}
