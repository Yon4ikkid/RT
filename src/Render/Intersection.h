#pragma once
#include "../Math/Vector.h"
#include "../Obj/Material.h"
// #include "../Obj/ISurface.h"



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
