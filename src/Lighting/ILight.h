#pragma once
#include "LightRay.h"

namespace Tracer
{
    class ILight
    {
    public:
        virtual LightRay get_light_ray(Vector& hitpoint) = 0;
        virtual ~ILight();
    };
}
