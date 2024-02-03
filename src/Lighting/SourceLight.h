#pragma once
#include "ILight.h"

namespace Tracer
{
    class SourceLight : public ILight
    {
    private:
        Vector source;
        float max_distance;

    public:
        SourceLight(Vector s, float md, const float r, const float g, const float b, const float ii);
        const Vector get_direction(const Vector p) override;
        const float get_intensity(const Vector p) override;
    };
}
