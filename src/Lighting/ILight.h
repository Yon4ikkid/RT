#pragma once
#include "../Render/Ray.h"

namespace Tracer
{
    class ILight
    {
    public:
        virtual Ray get_light_ray(Vector& hitpoint) = 0;
        virtual ~ILight();
    };
}
