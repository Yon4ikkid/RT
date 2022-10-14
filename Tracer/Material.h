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
		float __rdr;
		int __color[3];

		Material();
		Material(const int icolor[3], const float irdr);
	};
}
