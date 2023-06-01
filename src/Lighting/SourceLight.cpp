#include "SourceLight.h"

using namespace Tracer;

SourceLight::SourceLight(Vector s, float md, int color[3]) :  ILight(color), source(s), maxDistance(md) { }

LightRay SourceLight::get_light_ray(Vector& hitpoint)
{
    Vector direction = source - hitpoint;
    float distance = direction.norm();
    float intensity = std::max<float>(0, (maxDistance - distance) / maxDistance);
    return LightRay(hitpoint, direction * (1.0f / distance), intensity);
}