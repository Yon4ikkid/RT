#pragma once
#include "../Math/Vector.h"
#include "../Obj/Material.h"
#include "../Obj/ISurface.h"



namespace Tracer
{
    struct Intersection
    {
        float t;

        ISurface* s;
        Material m;
    };
}
