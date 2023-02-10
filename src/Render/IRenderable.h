/**
 * @file IRenderable.h
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Defines the IRenderable interface
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "Ray.h"

namespace Tracer
{
	class IRenderable
	{
	public:
		virtual bool intersect(const Ray& r, Vector& out) = 0;
		virtual ~IRenderable();
	};
}