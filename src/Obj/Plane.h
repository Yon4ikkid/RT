#pragma once
#include "ISurface.h"

namespace Tracer
{
    class Plane : public ISurface
    {
    private:
        Vector ab;
        Vector ac;
        Vector normal;
        
    public:
        Plane(Vector a, Vector b, Vector c);
        bool intersect(const Ray& r, float& out) override;
		Vector get_normal(const Vector& p) const override;
    }
}
