#pragma once
#include <thread>
#include <queue>
#include <mutex>
#include <utility>

#include "../Image/Image.h"

namespace Tracer
{
    Image RenderScene(const Scene& scene);
}
