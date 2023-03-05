#pragma once
#include <thread>
#include <queue>
#include <mutex>
#include <utility>

#include "../Image/Image.h"

namespace Tracer
{
    struct RenderTask
    {
    public:
        std::pair<int, int> anchor;
        int length;
        int width;
    };

    class Renderer
    {
    private:
        std::mutex task_mutex;
        std::queue<RenderTask> tasks;

        void worker();

    public:
        Renderer();
        void RenderImage(const Image& image);
    };
}
