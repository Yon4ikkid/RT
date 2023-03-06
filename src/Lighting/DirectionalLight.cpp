#include "DirectionalLight.h"
#include "../Render/Ray.h"
#include <algorithm>

using namespace Tracer;

DirectionalLight::DirectionalLight(Vector d) : direction(d.unit()) { }

float DirectionalLight::calculate_shading(Vector& point, Vector& normal, std::vector<IRenderable*>& objects)
{
    // Check for direct block
    Ray rev(point, -this->direction);

    float t;
    for (int k = 0; k < (int)objects.size(); k++)
        if (objects[k]->intersect(rev, t))
            return 0;
    
    // Calculate shading with normal
    return std::max<float>(0, normal * (-this->direction));
}
