#include "SourceLight.h"

using namespace Tracer;

SourceLight::SourceLight(Vector s, float ifm) : source(s), intensitfyFalloffModifier(ifm) { }

LightRay SourceLight::get_light_ray(Vector& hitpoint)
{
    Vector direction = source - hitpoint;
    float intensity = std::min(1.0f / (direction.norm() * this->intensitfyFalloffModifier), 1.0f);
    return LightRay(hitpoint, direction.unit(), intensity);
}