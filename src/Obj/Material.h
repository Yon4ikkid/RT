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
		float rdr;
		int color[3];

		Material();
		Material(const int r, const int g, const int b, const float irdr);
		Material(const int icolor[3], const float irdr);
	};
}
