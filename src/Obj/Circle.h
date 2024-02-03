#pragma once
#include "Plane.h"

namespace Tracer
{
    class Circle : public ISurface
    {
    private:
        Plane plane;
        float radius;

    public:
        Circle(const Vector a, const Vector n, const float r);
        std::optional<float> intersect(const Ray& r) override;
    };
}
