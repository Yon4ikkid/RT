/**
 * @file Ray.h
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Defines the Ray struct
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <iostream>
#include "../Math/Vector.h"

namespace Tracer
{
	struct Ray
	{
		Vector o;
		Vector d;

		Ray();
		Ray(const Vector& iorigin, const Vector& idirection);

		Vector operator()(const float t) const;
		friend std::ostream& operator<<(std::ostream& os, const Ray& r);
	};
}
