#pragma once
#include "../Render/IRenderable.h"
#include "Material.h"

namespace Tracer
{
	class ISurface : public IRenderable
	{
	private:
		Material surface_material;

	protected:
		virtual Vector get_normal(const Vector& p) const = 0;

	public:
		ISurface(const Material& material);
		Material get_material() const;
	};
}
