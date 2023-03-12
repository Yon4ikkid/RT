#pragma once
#include "../Math/Vector.h"
#include "../Obj/Material.h"

namespace Tracer
{
    struct Intersection
    {
        Vector p, n;
        Material m;
    };
}
