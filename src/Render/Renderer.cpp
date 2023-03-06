#include "Renderer.h"
#include "../Image/Image.h"
#include "../Env/Scene.h"
#include "../Obj/ISurface.h"
#include "Ray.h"
#include <iostream>

void Tracer::RenderScene(Scene& scene)
{
    int w = scene.camera.get_width();
    int h = scene.camera.get_height();
    Image img(scene.camera.get_height(), scene.camera.get_width());

    Ray r;
    IRenderable* obj;
    ISurface* surf;
    float closest = 0;
    float t = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            r = scene.camera.get_ray(i, j);

            std::cout << r << std::endl;
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
            if (surf != nullptr)
                img.SetPixel(i - 1, j - 1, surf->get_material().color);
        }

    img.Save();
}
