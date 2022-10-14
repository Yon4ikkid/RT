#pragma once
#include "IRenderable.h"
#include "Material.h"

namespace Tracer
{
	class ISurface : public IRenderable
	{
	private:
		Material __mat;

	protected:
		virtual Vector getNormal(const Vector& p) const = 0;

	public:
		ISurface(const Material& material);
		Material getMaterial() const;
	};
}
