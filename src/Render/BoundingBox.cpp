/**
 * @file BoundingBox.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Implementation for the BoundingBox class
 * @version 0.1
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "BoundingBox.h"

using namespace Tracer;

/**
 * @brief Construct a new Bounding Box:: Bounding Box object
 * 
 * @param a - lower-left corner
 * @param b - upper-right corner
 */
BoundingBox::BoundingBox(const Vector a, const Vector b) : a(a), b(b) { }

/**
 * @brief An auxiliary method for constructing a coordinate interval for a ray with the bounding box
 * 
 * @param ac - lower-left corner coordinate
 * @param bc - upper-right corner coordinate
 * @param oc - ray origin coordinate
 * @param dc - direction coordinate
 * @return Interval - the resulting interval
 */
Interval BoundingBox::construct_interval(const float ac, const float bc, const float oc, const float dc)
{
    Interval i(ac - oc, bc - oc);
    if (dc != 0)
    {
        i.a /= dc;
        i.b /= dc;
    }
    return i;
}

/**
 * @brief Checks whether the ray passes through (intersects) the bounding box
 * 
 * @param r - ray to be checked
 * @return true - intersects
 * @return false - does not intersect
 */
bool BoundingBox::is_ray_in(const Ray& r) const
{
    Interval i1 = this->construct_interval(this->a.x, this->b.x, r.o.x, r.d.x);
    Interval i2 = this->construct_interval(this->a.y, this->b.y, r.o.y, r.d.y);
    Interval i3 = this->construct_interval(this->a.z, this->b.z, r.o.z, r.d.z);
    return (i1 & i2) && i3;
}
