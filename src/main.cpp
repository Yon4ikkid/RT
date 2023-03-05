#include "Image/Image.h"

/**
 * @brief Main
 * 
 * @return int 
 */
int main()
{
    Tracer::Image img(100, 100);
    img.Save();
    
    return 0;
}

/*

The Z axis points upward in the space;
The Y axis points forward in the space;
The X axis points sideways in the space;
All axes are orthogonal;

*/