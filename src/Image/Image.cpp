#include "Image.h"
#define cimg_display 0
#include "CImg.h"

using namespace cimg_library;
using namespace Tracer;

Image::Image(const int l, const int w) : height(l), width(w)
{
    this->pixels = new Pixel[l * w];
}

void Image::SetPixel(const int r, const int c, Pixel p)
{
    this->pixels[c + r * this->width] = p;
}

void Image::SetArea(const std::pair<int,int> anchor, const int l, const int w, const Pixel* pixels)
{
    for (int i = 0; i < l; i++)
        for (int j = 0; j < w; j++)
            this->pixels[anchor.second + j + (anchor.first + i) * this->width] = pixels[j + i * w];
}

void Image::Save() 
{
    CImg<int> image(this->width, this->height, 1, 3, 0);
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            for (int k = 0; k < 3; k++)
                image(j, i, k) = this->pixels[j + i * this->width].value[k];
    image.save("output.jpeg");
}

Image::~Image()
{
    delete this->pixels;
}
