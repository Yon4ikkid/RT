#include "Render/Renderer.h"
#include "Env/Scene.h"
#include "Obj/Sphere.h"
#include "Obj/Plane.h"
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
    scene.camera = Camera(1080, 1920, 5000, Vector(0,-5000,0), 0,0,0);

    // scene.sceneObjects.push_back(new Sphere(Vector(-100,150,0), 50, Material(255,0,0,0)));
    // scene.sceneObjects.push_back(new Sphere(Vector(100,150,0), 80, Material(0,255,100,0)));
    Plane* p = new Plane(Vector(-500, 800, -860), Vector(0, 0, -860), Vector(500, 800, -860), Material(140,200,140,0));
    scene.sceneObjects.push_back(p);

    scene.lightSource = new DirectionalLight(Vector(0,0,-1));
    // scene.lightSource = new SourceLight(Vector(0, 50, 200), 700);

    render_scene(scene);

    return 0;
}

/*

The Z axis points upward in the space;
The Y axis points forward in the space;
The X axis points sideways in the space;
All axes are orthogonal;

*/