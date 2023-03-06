#pragma once
#include "../Math/Vector.h"
#include "../Render/IRenderable.h"
#include <vector>

namespace Tracer
{
    class ILight
    {
    public:
        virtual float calculate_shading(Vector& point, Vector& normal, std::vector<IRenderable*>& objects) = 0;
        virtual ~ILight();
    };
}
