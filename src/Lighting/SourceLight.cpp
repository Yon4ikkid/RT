#include "SourceLight.h"

using namespace Tracer;

SourceLight::SourceLight(Vector s) : source(s) { }

Ray SourceLight::get_light_ray(Vector& hitpoint)
{
    return Ray(hitpoint, (source - hitpoint).unit());
}