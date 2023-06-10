/**
 * @file Pixel.h
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Defines the pixel class
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
	struct Pixel
	{
		int value[3];

		Pixel();
		Pixel(const unsigned int r, const unsigned int g, const unsigned int b);
		Pixel(const Vector v);
		Pixel(const Pixel& other);

		Pixel& operator=(const Pixel& other);
	};
}
