#include "Pixel.h"

using namespace Tracer;

Pixel::Pixel()
{
	__value[0] = 0;
	__value[1] = 0;
	__value[2] = 0;
}

Pixel::Pixel(const unsigned int r, const unsigned int g, const unsigned int b)
{
	__value[0] = r;
	__value[1] = g;
	__value[2] = b;
}

Pixel::Pixel(const int value[3]) : Pixel(value[0], value[1], value[2]) { }

Pixel::Pixel(const Pixel& other) : Pixel(other.__value) { }

Pixel& Pixel::operator=(const Pixel& other)
{
	this->__value[0] = other.__value[0];
	this->__value[1] = other.__value[1];
	this->__value[2] = other.__value[2];

	return *this;
}

Pixel& Pixel::operator=(const int value[3])
{
	this->__value[0] = value[0];
	this->__value[1] = value[1];
	this->__value[2] = value[2];

	return *this;
}

Tracer::Pixel::operator sf::Color() const
{
	return sf::Color(__value[0], __value[1], __value[2], 255);
}
