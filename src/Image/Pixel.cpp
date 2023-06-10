/**
 * @file Pixel.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Provides implementation for the Pixel class
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Pixel.h"

using namespace Tracer;

Pixel::Pixel()
{
	value[0] = 0;
	value[1] = 0;
	value[2] = 0;
}

Pixel::Pixel(const unsigned int r, const unsigned int g, const unsigned int b)
{
	value[0] = r;
	value[1] = g;
	value[2] = b;
}

Pixel::Pixel(const Vector v) 
{
	this->value[0] = v.x * 255.0;
	this->value[1] = v.y * 255.0;
	this->value[2] = v.z * 255.0;
}

Pixel::Pixel(const Pixel& other) 
{
	this->value[0] = other.value[0];
	this->value[1] = other.value[1];
	this->value[2] = other.value[2];
}

Pixel& Pixel::operator=(const Pixel& other)
{
	this->value[0] = other.value[0];
	this->value[1] = other.value[1];
	this->value[2] = other.value[2];

	return *this;
}
