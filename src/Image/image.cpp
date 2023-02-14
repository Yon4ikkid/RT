#include "Image.h"
#include "Pixel.h"

using namespace Tracer;

Image(int l, int w) : length(l), width(w)
{
    this->pixels = new Pixel[l * w];
}

~Image()
{
    delete this->pixels;
}
