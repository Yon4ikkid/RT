#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "Screen.h"

#define CAM_W 500
#define CAM_H 500
#define FOCAL_D 500

int main()
{
    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    */

    Tracer::Vector camSP(250, 0, 250);
    Tracer::Camera c(CAM_W, CAM_H, FOCAL_D, camSP, 0, 0, 0);
    std::cout << "Camera:\n" << c;

    Tracer::Screen s(CAM_W, CAM_H);
    for (int i = 0; i < CAM_W; i++)
        s.set(i, 50, Tracer::Pixel(255, 255, 255));

    s.display();
    system("pause");
    return 0;
}

/*

The Z axis points upward in the space;
The Y axis points forward in the space;
The X axis points sideways in the space;
All axes are orthogonal;

*/