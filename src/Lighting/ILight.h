#pragma once
#include "../Math/Vector.h"

namespace Tracer
{
    class ILight
    {
    private: 
        Vector color;
    
    protected:
        float initial_intensity;

    public:
        ILight();
        ILight(const float r, const float g, const float b, float ii);
        const Vector get_color() const;
        virtual const Vector get_direction(const Vector p) = 0;
        virtual const float get_intensity(const Vector p) = 0;
        virtual ~ILight();
    };
}
