#pragma once
#include "Vector.h"

namespace Tracer
{
	struct Ray
	{
		Vector o;
		Vector d;

		Ray();
		Ray(const Vector& iorigin, const Vector& idirection);

		Vector operator()(const float t) const;
	};
}
