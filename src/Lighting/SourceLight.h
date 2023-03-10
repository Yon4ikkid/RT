#pragma once
#include "ILight.h"

namespace Tracer
{
    class SourceLight : public ILight
    {
    private:
        Vector source;
        float maxDistance;

    public:
        SourceLight(Vector s, float md);
        virtual LightRay get_light_ray(Vector& hitpoint) override;
    };
}
