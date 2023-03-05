#pragma once
#include <vector>
#include <utility>

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
        Image(const int l, const int w);
        SetPixel(const int r, const int c, Pixel p);
        SetArea(const std::pair<int,int> anchor, const int l, const int w, const Pixel* pixels);
        ~Image();
    };
}
