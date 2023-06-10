#pragma once
#include "../Math/Vector.h"
#include "Ray.h"

namespace Tracer
{
    struct BoundingBox
    {
        Vector a,b;

        bool is_ray_in(const Ray& r) const;
    };
}
