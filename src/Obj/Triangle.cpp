#include "Triangle.h"

using namespace Tracer;

Triangle::Triangle(Vector a, Vector b, Vector c, const Material& material) : ISurface(material), ab(b - a), ac(c - a)
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

    this->normal = ;
    this->p = a;
    this->plane = Plane(a, Vector(N.v[0][0], N.v[1][0], 1).unit(), material)
}

bool Triangle::intersect(const Ray& r, float& out) override
{
    if (!Plane::intersect(r, out))
        return false;

    Vector p = r(t) - a;

    Matrix A(2,2);
    A.v[0][0] = ab.x;
    A.v[0][1] = ac.x;
    A.v[1][0] = ab.y;
    A.v[1][1] = ac.y;

    Matrix X(2,1);
    X.v[0][0] = p.x;
    X.v[1][0] = p.y;

    Matrix C = A.inverse() * X;
    float alpha = C.v[0][0], beta = C.v[1][0];
    float s = alpha + beta;

    if (std::abs(s) <= 1 && alpha >= 0 && beta >= 0)
        return true;
    
    return false;
}

Vector Triangle::get_normal(const Vector& p) const override
{

}
