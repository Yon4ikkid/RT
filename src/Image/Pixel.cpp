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

Pixel::Pixel(const int value[3]) : Pixel(value[0], value[1], value[2]) { }

Pixel::Pixel(const Pixel& other) : Pixel(other.value) { }

Pixel& Pixel::operator=(const Pixel& other)
{
	this->value[0] = other.value[0];
	this->value[1] = other.value[1];
	this->value[2] = other.value[2];

	return *this;
}

Pixel& Pixel::operator=(const int value[3])
{
	this->value[0] = value[0];
	this->value[1] = value[1];
	this->value[2] = value[2];

	return *this;
}
