#include "ISurface.h"

using namespace Tracer;

ISurface::ISurface(const Material& material) : __mat(material) { }

Material ISurface::getMaterial() const
{
	return __mat;
}
