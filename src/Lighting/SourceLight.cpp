#include "SourceLight.h"

using namespace Tracer;

SourceLight::SourceLight(Vector s, float md, const float r, const float g, const float b, const float ii) :  ILight(r,g,b,ii), source(s), max_distance(md) { }

const Vector SourceLight::get_direction(const Vector p)
{
    return (p - this->source).unit();
}

const float SourceLight::get_intensity(const Vector p)
{
    return std::max<float>(1.0 - (p - this->source).norm() / this->max_distance, 0.0);
}
