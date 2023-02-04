#include "ISurface.h"

using namespace Tracer;

ISurface::ISurface(const Material& material) : surface_material(material) { }

Material ISurface::get_material() const
{
	return surface_material;
}
