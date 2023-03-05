#include "Renderer.h"
#include "../Image/Image.h"
#include "../Env/Scene.h"
#include "Ray.h"
#include <iostream>

void Tracer::RenderScene(Scene& scene)
{
    int w = scene.camera.get_width();
    int h = scene.camera.get_height();
    Image img(scene.camera.get_width(), scene.camera.get_height());

    Ray r;
    float closest = 0;
    float t = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            r = scene.camera.get_ray(i, j);

            for (int k = 0; k < (int)scene.sceneObjects.size(); k++)
                if (scene.sceneObjects[k]->intersect(r, t))
                    if (closest == 0 || closest > t)
                        closest = t;

            if (closest == 0)
                continue;
            
            img.SetPixel(i, j, {255,0,0});
        }

    img.Save();
}
