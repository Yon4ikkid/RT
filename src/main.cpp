#include "Render/Renderer.h"
#include "Env/Scene.h"
#include "Obj/Sphere.h"
#include "Obj/Material.h"
#include <iostream>

using namespace Tracer;

/**
 * @brief Main
 * 
 * @return int 
 */
int main()
{
    Scene scene;
    scene.camera = Camera(400, 800, 5000, Vector(0,-5000,0), 0,0,0);
    std::cout << scene.camera << std::endl;
    // scene.sceneObjects.push_back(new Sphere(Vector(-50,150,0), 5, Material(255,0,0,0)));
    scene.sceneObjects.push_back(new Sphere(Vector(50,1200,0), 5, Material(0,255,0,0)));

    RenderScene(scene);

    return 0;
}

/*

The Z axis points upward in the space;
The Y axis points forward in the space;
The X axis points sideways in the space;
All axes are orthogonal;

*/