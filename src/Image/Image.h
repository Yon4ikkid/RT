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
        int height;
        int width;

    public:
        Image(const int l, const int w);
        void SetPixel(const int r, const int c, Pixel p);
        void SetArea(const std::pair<int,int> anchor, const int l, const int w, const Pixel* pixels);
        void Save();
        ~Image();
    };
}
