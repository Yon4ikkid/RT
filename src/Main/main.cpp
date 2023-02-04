#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "Screen.h"
#include "Sphere.h"
#include "Renderer.h"

#define CAM_W 500
#define CAM_H 500
#define FOCAL_D 500
#define THREAD_NUM 5

int main()
{
    Tracer::Vector camSP(250, 0, 250);
    Tracer::Camera c(CAM_W, CAM_H, FOCAL_D, camSP, 0, 0, 0);
    std::cout << "Camera:\n" << c;

    Tracer::Screen s(CAM_W, CAM_H);

    Tracer::Scene scene;
    scene.camera = &c;

    Tracer::Material m(255, 0, 0, 1);
    scene.sceneObjects.push_back(new Tracer::Sphere(Tracer::Vector(250, 150, 250), 20, m));
    Tracer::Renderer r(THREAD_NUM, &scene, &s);
    r.render();

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