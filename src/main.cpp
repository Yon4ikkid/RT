#include "Render/Renderer.h"
#include "Env/Scene.h"
#include "Obj/Sphere.h"
#include "Obj/Material.h"

using namespace Tracer;

/**
 * @brief Main
 * 
 * @return int 
 */
int main()
{
    Scene scene;
    scene.camera = Camera(200, 200, 200, Vector(0,0,0), 0,0,0);
    scene.sceneObjects.push_back(new Sphere(Vector(0,0,300), 50, Material(255,0,0,0)));

    RenderScene(scene);

    return 0;
}

/*

The Z axis points upward in the space;
The Y axis points forward in the space;
The X axis points sideways in the space;
All axes are orthogonal;

*/