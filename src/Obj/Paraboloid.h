#pragma once
#include "ISurface.h"

namespace Tracer
{
    class Paraboloid : public ISurface
    {
    private:
        Vector focus, axis;
        float focal_length, length;
        
    protected:
        Vector get_normal(const Vector& p) const override;

    public:
        Paraboloid();
        Paraboloid(Vector apex, Vector n, float focal_length, float length);
        std::optional<float> intersect(const Ray& r) override;
    };
}
