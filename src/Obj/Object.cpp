#include "Object.h"
#include <cmath>

using namespace Tracer;


Object::Object() : surface(nullptr) { }


Object::Object(const Material surface_material, ISurface* const surface) 
    : surface_material(surface_material), surface(surface) { }


Object::~Object()
{
    delete this->surface;
}


Material Object::get_material() const
{
    return this->surface_material;
}
        

bool Object::intersect(const Ray& r, Intersection& out)
{
    auto t_opt = this->surface->intersect(r);
    out.t = t_opt.value_or(0);
    if (!t_opt.has_value())
        return false;
    out.m = this->surface_material;
    out.s = this->surface;
    return t_opt.has_value() && t_opt.value() > 0;
}
