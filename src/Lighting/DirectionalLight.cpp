#include "DirectionalLight.h"
#include "../Render/Ray.h"
#include <algorithm>

using namespace Tracer;

DirectionalLight::DirectionalLight(Vector d, const float r, const float g, const float b, const float ii) : ILight(r,g,b,ii), direction(d.unit()) { }

const Vector DirectionalLight::get_direction(const Vector p)
{
    return this->direction;
}

const float DirectionalLight::get_intensity(const Vector p)
{
    return this->initial_intensity;
}
