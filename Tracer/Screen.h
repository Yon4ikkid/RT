#pragma once
#include <SFML/Graphics.hpp>

#include "Pixel.h"

namespace Tracer
{
	class Screen
	{
	private:
		sf::RenderWindow* __rw;
		sf::Image __i;
		sf::Texture __t;
		sf::Sprite __s;
		unsigned int __width;
		unsigned int __height;

	public:
		Screen(unsigned int iwidth, unsigned int iheight);
		~Screen();

		void set(const unsigned int x, const unsigned int y, const Pixel& val);
		void display();
	};
}
