#pragma once
#include "Plane.h"

namespace Tracer
{
    class Circle : public IRenderable
    {
    private:
        Plane plane;
        float radius;

    public:
        Circle(const Vector a, const Vector n, const float r, const Material& material);
        bool intersect(const Ray& r, Intersection& out) override;
    };
}
