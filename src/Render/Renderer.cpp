#include "Renderer.h"
#include "../Image/Image.h"
#include "../Env/Scene.h"
#include "../Obj/ISurface.h"
#include "Ray.h"
#include "../Lighting/LightRay.h"
#include <iostream>

using namespace Tracer;

float calculate_shading(Ray r, Vector& n, Scene& scene, IRenderable* exception)
{
    float t;
    for (int k = 0; k < (int)scene.sceneObjects.size(); k++)
        if (scene.sceneObjects[k] != exception && scene.sceneObjects[k]->intersect(r, t))
            return 0;

    return std::max<float>(0, n * r.d);
}

void Tracer::render_scene(Scene& scene)
{
    int w = scene.camera.get_width();
    int h = scene.camera.get_height();
    Image img(scene.camera.get_height(), scene.camera.get_width());

    Ray r;
    LightRay lightRay;
    IRenderable* obj;
    ISurface* surf;
    Vector p, normal;
    float closest = 0, t = 0, coef = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            closest = 0;
            r = scene.camera.get_ray(i, j);

            for (int k = 0; k < (int)scene.sceneObjects.size(); k++)
                if (scene.sceneObjects[k]->intersect(r, t))
                    if (closest == 0 || closest > t)
                    {
                        closest = t;
                        obj = scene.sceneObjects[k];
                    }

            if (closest == 0) 
                continue;
            
            surf = dynamic_cast<ISurface*>(obj);
            if (surf == nullptr)
                continue;
            
            p = r(closest);
            normal = surf->get_normal(p);
            
            lightRay = scene.lightSource->get_light_ray(p);
            coef = calculate_shading(lightRay, normal, scene, obj);
            img.SetPixel(i - 1, j - 1, (Pixel)surf->get_material().color * coef * lightRay.intensity);
        }

    img.Save();
}
