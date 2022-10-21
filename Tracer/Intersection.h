#pragma once
#include "Vector.h"
#include "Material.h"
#include "Pixel.h"

namespace Tracer
{
	// Represents an intersection between a ray and an object
	struct Intersection
	{
		Vector point;	// Point of intersection
		Vector normal;	// Surface normal at point of intersection
		Material m;	// Object material
	};
}
