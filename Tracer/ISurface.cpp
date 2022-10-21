#include "ISurface.h"

using namespace Tracer;

ISurface::ISurface(const Material& material) : mat(material) { }

Material ISurface::getMaterial() const
{
	return mat;
}
