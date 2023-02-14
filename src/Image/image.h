#pragma once
#include "Pixel.h"
#include <vector>


namespace Tracer
{
    class Image
    {
    private:
        Pixel pixels;
        int length;
        int width;

    public:
        Image(int l, int w);
        ~Image();
    };
}
