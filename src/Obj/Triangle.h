#pragma once
#include "Plane.h"

namespace Tracer 
{
    class Triangle : public IRenderable
    {
    private:
        Plane p;
        Vector u, v;

    public:
        Triangle(const Vector a, const Vector b, const Vector c, const Material& material);
        bool intersect(const Ray& r, Intersection& out) override;
    };
}
