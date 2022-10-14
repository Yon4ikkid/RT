#include "Material.h"

using namespace Tracer;

Material::Material() : __rdr(0), __color{ 255, 0, 0 } { }

Material::Material(const int color[3], const float rdr)
	: __rdr(rdr), __color{ color[0], color[1], color[2] } { }
