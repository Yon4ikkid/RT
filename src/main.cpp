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
    const float focus = 4000;
    Scene scene;
    scene.camera = Camera(1080, 1920, focus, Vector(0,-focus,0), 0,0,0);
    std::cout << scene.camera << std::endl;
    scene.sceneObjects.push_back(new Sphere(Vector(-400,140,50), 90, Material(255,0,0,0)));
    scene.sceneObjects.push_back(new Sphere(Vector(300,150,-100), 140, Material(0,255,100,0)));
    Plane* p = new Plane(Vector(-420, 150, -200), Vector(320, 210, -200), Vector(-20, 50, -200), Material(140,200,140,0));
    std::cout << p->get_normal(Vector()) << '\n';
    scene.sceneObjects.push_back(p);

    // scene.lightSource = new DirectionalLight(Vector(2,2,-1));
    scene.lightSource = new SourceLight(Vector(0, 50, 200), 4000);

    render_scene(scene);

    return 0;
}

/*

The Z axis points upward in the space;
The Y axis points forward in the space;
The X axis points sideways in the space;
All axes are orthogonal;

*/