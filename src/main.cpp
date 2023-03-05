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
    scene.camera = Camera(200, 200, 500, Vector(100,-500,100), 0,0,0);
    scene.sceneObjects.push_back(new Sphere(Vector(100,200,100), 2, Material(255,0,0,0)));

    RenderScene(scene);

    return 0;
}

/*

The Z axis points upward in the space;
The Y axis points forward in the space;
The X axis points sideways in the space;
All axes are orthogonal;

*/