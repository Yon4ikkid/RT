#pragma once
#include "../Math/Vector.h"
#include "../Obj/Material.h"


namespace Tracer
{
    class ISurface;
    struct Intersection
    {
        float t;
        ISurface* s;
        Material m;
    };
}
