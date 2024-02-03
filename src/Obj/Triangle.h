#pragma once
#include "Plane.h"

namespace Tracer 
{
    class Triangle : public ISurface
    {
    private:
        Plane p;
        Vector u, v;

    public:
        Triangle(const Vector a, const Vector b, const Vector c);
        std::optional<float> intersect(const Ray& r) override;
    };
}
