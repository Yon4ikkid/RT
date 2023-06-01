#pragma once
#include "LightRay.h"

namespace Tracer
{
    class ILight
    {
    private: 
        int color[3];

    public:
        ILight();
        ILight(const int r, const int g, const int b);
        ILight(const int values[3]);
        const int* get_color() const;
        virtual LightRay get_light_ray(Vector& hitpoint) = 0;
        virtual ~ILight();
    };
}
