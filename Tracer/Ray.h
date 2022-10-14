#pragma once
#include "Vector.h"

namespace Tracer
{
	struct Ray
	{
		Vector __o;
		Vector __d;

		Ray();
		Ray(const Vector& iorigin, const Vector& idirection);

		Vector operator()(const float t) const;
	};
}
