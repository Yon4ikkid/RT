#pragma once
#include "Plane.h"

namespace Tracer 
{
    class Triangle : public IRenderable
    {
    private:
        Plane plane;
        Vector u, v;

    public:
        Triangle(const Vector a, const Vector b, const Vector c, const Material& material);
        bool intersect(const Ray& r, float& out) override;
		// Vector get_normal(const Vector& p) const override;
    }
}
