#pragma once
#include "ISurface.h"

namespace Tracer
{
    class Plane : public ISurface
    {
    private:
        Vector p, normal;
        
    protected:
        Vector get_normal(const Vector& p) const override;

    public:
        Plane();
        Plane(Vector p, Vector n, const Material& material);
        Vector get_pivot() const;
        bool intersect(const Ray& r, Intersection& out) override;
    };
}
