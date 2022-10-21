#include "Screen.h"
#include <exception>

using namespace Tracer;

Screen::Screen(unsigned int width, unsigned int height)
	: width(width), height(height)
{
	rw = new sf::RenderWindow(sf::VideoMode(width, height), "Render Window");
	i.create(width, height, sf::Color(0,0,0,1));
}

Screen::~Screen()
{
	rw->close();
	delete rw;
}

void Tracer::Screen::set(const unsigned int x, const unsigned int y, const Pixel& val)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		throw std::runtime_error("Access index out of range");
	
	i.setPixel(x, y, (sf::Color)val);
}

void Tracer::Screen::display()
{
	t.loadFromImage(i);
	s.setTexture(t, true);
	rw->draw(s);
	rw->display();
}

unsigned int Tracer::Screen::GetHeight() const
{
	return this->height;
}

unsigned int Tracer::Screen::GetWidth() const
{
	return this->width;
}
