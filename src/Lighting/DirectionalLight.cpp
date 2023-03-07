#include "DirectionalLight.h"
#include "../Render/Ray.h"
#include <algorithm>

using namespace Tracer;

DirectionalLight::DirectionalLight(Vector d) : direction(d.unit()) { }

Ray DirectionalLight::get_light_ray(Vector& hitpoint)
{
    return Ray(hitpoint, -this->direction);
}
