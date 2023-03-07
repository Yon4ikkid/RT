#pragma once
#include "../Render/Ray.h"

namespace Tracer
{
    struct LightRay : public Ray
    {
    public:
        float intensity;
        
        LightRay();
        LightRay(Vector o, Vector d, float i);
    };
}
