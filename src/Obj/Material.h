/**
 * @file Material.h
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Defines the Material struct
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "../Math/Vector.h"

namespace Tracer
{
	// The visual properties of a uniform surface. 
	struct Material
	{
	public:
		// Reflective diffusion ratio:
		// All surfaces in the Tracer are reflective,
		//	yet the measure of the randomness and softness
		//	of the reflection varies.
		float roughness;
		float transmission;
		Vector color;

		Material();
		Material(const float r, const float g, const float b, const float irdr, float trn);
	};
}
