#include "DirectionalLight.h"
#include "../Render/Ray.h"
#include <algorithm>

using namespace Tracer;

DirectionalLight::DirectionalLight(Vector d, int color[3]) : ILight(color), direction(d.unit()) { }

LightRay DirectionalLight::get_light_ray(Vector& hitpoint)
{
    return LightRay(hitpoint, -this->direction, 1.0f);
}
