#pragma once
#include "ISurface.h"

namespace Tracer
{
    class Plane : public ISurface
    {
    protected:
        Vector p, normal;
        
    public:
        Plane(Vector p, Vector n, const Material& material);
        bool intersect(const Ray& r, Intersection& out) override;
		Vector get_normal(const Vector& p) const override;
    };
}
