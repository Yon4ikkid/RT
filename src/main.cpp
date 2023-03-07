#include "Render/Renderer.h"
#include "Env/Scene.h"
#include "Obj/Sphere.h"
#include "Obj/Material.h"
#include <iostream>
#include "Lighting/SourceLight.h"
#include "Lighting/DirectionalLight.h"

using namespace Tracer;

/**
 * @brief Main
 * 
 * @return int 
 */
int main()
{
    Scene scene;
    scene.camera = Camera(400, 600, 5000, Vector(0,-5000,0), 0,0,0);
    // std::cout << scene.camera << std::endl;
    scene.sceneObjects.push_back(new Sphere(Vector(-100,150,0), 50, Material(255,0,0,0)));
    scene.sceneObjects.push_back(new Sphere(Vector(100,150,0), 80, Material(0,255,100,0)));
    // scene.lightSource = new DirectionalLight(Vector(1,0,-1));
    scene.lightSource = new SourceLight(Vector(0, 50, 200), 0.005);
    render_scene(scene);

    return 0;
}

/*

The Z axis points upward in the space;
The Y axis points forward in the space;
The X axis points sideways in the space;
All axes are orthogonal;

*/