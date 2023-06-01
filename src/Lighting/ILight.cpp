#include "ILight.h"

using namespace Tracer;

ILight::ILight() : color({0,0,0}) { }

ILight::ILight(const int r, const int g, const int b) : color({r,g,b}) { }
ILight::ILight(const int values[3]) : ILight(values[0], values[1], values[2]) { }

const int* ILight::get_color() const {
    return this->color;
}

ILight::~ILight()
{
    
}
