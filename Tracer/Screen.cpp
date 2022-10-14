#include "Screen.h"
#include <exception>

using namespace Tracer;

Screen::Screen(unsigned int width, unsigned int height)
	: __width(width), __height(height)
{
	__rw = new sf::RenderWindow(sf::VideoMode(width, height), "Render Window");
	__i.create(width, height, sf::Color(0,0,0,1));
}

Screen::~Screen()
{
	__rw->close();
	delete __rw;
}

void Tracer::Screen::set(const unsigned int x, const unsigned int y, const Pixel& val)
{
	if (x < 0 || x >= __width || y < 0 || y >= __height)
		throw std::runtime_error("Access index out of range");
	
	__i.setPixel(x, y, (sf::Color)val);
}

void Tracer::Screen::display()
{
	__t.loadFromImage(__i);
	__s.setTexture(__t, true);
	__rw->draw(__s);
	__rw->display();
}
