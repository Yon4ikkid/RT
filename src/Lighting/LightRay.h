#pragma once
#include "../Render/Ray.h"

namespace Tracer
{
    struct LightRay : public Ray
    {
    public:
        float intensity;
        int color[3];
        
        LightRay();
        LightRay(Vector o, Vector d, float i);
    };
}
