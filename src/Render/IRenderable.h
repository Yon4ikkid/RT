#pragma once
#include "Ray.h"

namespace Tracer
{
	// An interface for any object which intersection
	//	with a ray can be mathematically computed and represented
	//	on screen.
	class IRenderable
	{
	public:
		virtual bool intersect(const Ray& r, Vector& out) = 0;
		virtual ~IRenderable();
	};
}