#pragma once
#include "ILight.h"

namespace Tracer
{
    class SourceLight : public ILight
    {
    private:
        Vector source;
        float intensitfyFalloffModifier;

    public:
        SourceLight(Vector s, float ifm);
        virtual LightRay get_light_ray(Vector& hitpoint) override;
    };
}
