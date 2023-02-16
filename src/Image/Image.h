#pragma once
#include <vector>

#include "Pixel.h"

namespace Tracer
{
    class Image
    {
    private:
        Pixel* pixels;
        int length;
        int width;

    public:
        Image(int l, int w);
        ~Image();
    };
}
