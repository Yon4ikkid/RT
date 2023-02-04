#pragma once

namespace Tracer
{
	struct Pixel
	{
		int value[3];

		Pixel();
		Pixel(const unsigned int r, const unsigned int g, const unsigned int b);
		Pixel(const int ivalue[3]);
		Pixel(const Pixel& other);

		Pixel& operator=(const Pixel& other);
		Pixel& operator=(const int ivalue[3]);
	};
}
