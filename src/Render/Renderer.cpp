#include "Renderer.h"
#include "../Image/Image.h"
#include "../Env/Scene.h"
#include "../Obj/ISurface.h"
#include "Intersection.h"
#include "Ray.h"
#include <iostream>
#include <limits>

using namespace Tracer;

struct Incidence {
    Vector n;
    Vector p;
    Material m;
};

float calculate_shading(Ray r, Vector n, Scene& scene)
{
    return std::max<float>(0, n * r.d);
}

/**
 * @brief Finds the closest intersection of the ray with the given set of objects
 * 
 * @param objects - set of target objects
 * @param r - the ray
 * @param out - incidence information (if found)
 * @return true - found intersection
 * @return false - no intersection found
 */
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

Vector trace_ray(Scene& scene, const Ray& r) 
{
    Incidence incid;
    if (!find_closest_intersection(scene.sceneObjects, r, incid))
        return scene.lightSource->get_color() * calculate_shading(r, incid.n, scene);
    
    return incid.m.color;
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
            img.SetPixel(i - 1, j - 1, (Pixel)trace_ray(scene, r));
        }
    img.Save();
}
