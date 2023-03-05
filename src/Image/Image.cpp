#include "Image.h"

Image(const int l, const int w) : length(l), width(w)
{
    this->pixels = new Pixel[l * w];
}

SetPixel(const int r, const int c, Pixel p)
{
    this->pixels[c + r * this->width];
}

SetArea(const std::pair<int,int> anchor, const int l, const int w, const Pixel* pixels)
{

}

~Image()
{
    delete this->pixels;
}
