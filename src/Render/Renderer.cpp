#include "Renderer.h"
#include "../Image/Image.h"
#include "../Env/Scene.h"
#include "../Obj/ISurface.h"
#include "Intersection.h"
#include "Ray.h"
#include "../Lighting/LightRay.h"
#include <iostream>
#include <limits>

using namespace Tracer;

struct Incidence {
    Vector n;
    Vector p;
    Material m;
};

float calculate_shading(Ray r, Vector& n, Scene& scene)
{
    return std::max<float>(0, n * r.d);
}

bool find_closest_intersection(std::vector<IRenderable*>& objects, const Ray& r, Incidence& out)
{
    Intersection intersection;
    IRenderable* obj = NULL;

    float closest = std::numeric_limits<float>::max();
    for (int k = 0; k < (int)objects.size(); k++)
        if (objects[k]->intersect(r, intersection))
            if (closest > intersection.t)
            {
                closest = intersection.t;
                obj = objects[k];
            }

    if (obj == NULL)
        return false;

    out.m = intersection.m;
    out.p = r(intersection.t);
    out.n = intersection.s->get_normal(out.p);

    return true;
}

Pixel trace_ray(Scene& scene, const Ray& r) 
{
    Incidence incid;
    if (!find_closest_intersection(scene.sceneObjects, r, incid))
    { // Light
        LightRay lr = scene.lightSource->get_light_ray(incid.p);
        float coef =  std::max<float>(0, incid.n * r.d);
        return (Pixel)scene.lightSource->get_color() * coef * lr.intensity;
    }
    
    return (Pixel)incid.m.color;
}

void Tracer::render_scene(Scene& scene)
{
    int w = scene.camera.get_width();
    int h = scene.camera.get_height();
    Image img(scene.camera.get_height(), scene.camera.get_width());

    Ray r;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            r = scene.camera.get_ray(i, j);
            img.SetPixel(i - 1, j - 1, trace_ray(scene, r));
        }
    img.Save();
}
