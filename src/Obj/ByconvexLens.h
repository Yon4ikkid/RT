#pragma once
#include "ISurface.h"
#include "Sphere.h"

namespace Tracer
{
    class BiconvexLens: public ISurface
    {
    private:
        Sphere sp1, sp2;
        Vector c;
        float r, a;
        
    protected:
        Vector get_normal(const Vector& p) const override;

    public:
        BiconvexLens();
        BiconvexLens(const Vector center, const Vector axis, const float curv_radius, const float sub_ratio);
        
        std::optional<float> intersect(const Ray& r) override;
    };
}
