#include "ILight.h"

using namespace Tracer;

ILight::ILight() : color({0,0,0}) { }

ILight::ILight(const float r, const float g, const float b, const float ii) : color({r / 255.0f,g / 255.0f,b / 255.0f}), initial_intensity(ii) { }

const Vector ILight::get_color() const {
    return this->color;
}

ILight::~ILight()
{
    
}
