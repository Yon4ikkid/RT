#pragma once
#include "ILight.h"

namespace Tracer
{
    class DirectionalLight : public ILight
    {
    private:
        Vector direction;

    public:
        DirectionalLight(Vector direction, const float r, const float g, const float b, float ii); 
        const Vector get_direction(const Vector p) override;
        const float get_intensity(const Vector p) override;
    };
}
