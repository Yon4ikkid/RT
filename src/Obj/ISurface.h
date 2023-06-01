/**
 * @file ISurface.h
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Defines the ISurface interface
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "../Render/IRenderable.h"
#include "Material.h"

namespace Tracer
{
	class ISurface : public IRenderable
	{
	private:
		Material surface_material;

	public:
		ISurface(const Material& material);
		Material get_material() const;
		virtual Vector get_normal(const Vector& p) const = 0;
	};
}
