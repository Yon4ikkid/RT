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
#include <optional>

namespace Tracer
{
	class ISurface
	{
	public:
		virtual std::optional<float> intersect(const Ray& r) = 0;
		virtual Vector get_normal(const Vector& p) const = 0;
	};
}
