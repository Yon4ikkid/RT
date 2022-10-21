#pragma once
#include <SFML/Graphics.hpp>

#include "Pixel.h"

namespace Tracer
{
	class Screen
	{
	private:
		sf::RenderWindow* rw;
		sf::Image i;
		sf::Texture t;
		sf::Sprite s;
		unsigned int width;
		unsigned int height;

	public:
		Screen(unsigned int iwidth, unsigned int iheight);
		~Screen();

		void set(const unsigned int x, const unsigned int y, const Pixel& val);
		void display();

		unsigned int GetHeight() const;
		unsigned int GetWidth() const;
	};
}
