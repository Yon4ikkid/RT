#pragma once
#include <vector>

#include "Pixel.h"

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
