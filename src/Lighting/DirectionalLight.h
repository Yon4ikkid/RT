#pragma once
#include "ILight.h"

namespace Tracer
{
    class DirectionalLight : public ILight
    {
    private:
        Vector direction;

    public:
        DirectionalLight(Vector direction); 
        virtual LightRay get_light_ray(Vector& hitpoint) override;
    };
}
