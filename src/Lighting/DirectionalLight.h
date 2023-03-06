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
        float calculate_shading(Vector& point, Vector& normal, std::vector<IRenderable*>& objects) override;  
    };
}
