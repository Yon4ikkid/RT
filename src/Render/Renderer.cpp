#include "Renderer.h"
#include "../Image/Image.h"
#include "../Env/Scene.h"
#include "../Obj/ISurface.h"
#include "Intersection.h"
#include "Ray.h"
#include <iostream>
#include <thread>

using namespace Tracer;

struct Incidence
{
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


void render_fragment(Scene& scene, Image& img, int start_row, int end_row, int start_col, int end_col)
{
    Ray r;
    for (int row = start_row; row <= end_row; row++)
        for (int col = start_col; col <= end_col; col++)
        {
            r = scene.camera.get_ray(row, col);
            img.SetPixel(row - 1, col - 1, (Pixel)trace_ray(scene, r));
        }
}

void ATT(int z)
{
    std::cout << "A";
}


void Tracer::render_scene(Scene &scene, const int job_count)
{
    int w = scene.camera.get_width();
    int h = scene.camera.get_height();
    Image img(scene.camera.get_height(), scene.camera.get_width());
    std::vector<std::thread> workers;

    int start_row = 1, delta = h / job_count, end_row = delta;
    //std::thread t(ATT, 0);
    for (int current_job = 1; current_job < job_count; current_job++)
    {

        //workers.push_back(std::move(std::thread(render_fragment, std::ref(scene), std::ref(img), start_row, end_row, 1, w)));
        start_row += delta;
        end_row += delta;
    }
    end_row = h;
    //workers.push_back(std::move(std::thread(render_fragment, std::ref(scene), std::ref(img), start_row, end_row, 1, w)));

    for (std::thread& t: workers)
        t.join();

    img.Save();
}
