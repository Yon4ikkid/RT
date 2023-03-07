#pragma once
#include "ILight.h"

namespace Tracer
{
    class SourceLight : public ILight
    {
    private:
        Vector source;

    public:
        SourceLight(Vector s);
        virtual Ray get_light_ray(Vector& hitpoint) override;
    };
}
