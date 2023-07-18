/**
 * @file BoundingBox.h
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Definition of the BoundingBox class
 * @version 0.1
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "../Math/Vector.h"
#include "Ray.h"
#include "IRenderable.h"
#include "../Math/Interval.h"

namespace Tracer
{
    class BoundingBox
    {
    private:
        Vector a;
        Vector b;

        static Interval construct_interval(const float ac, const float bc, const float oc, const float dc);

    public:
        BoundingBox(const Vector a, const Vector b);
        bool is_ray_in(const Ray& r) const;
    };
}
