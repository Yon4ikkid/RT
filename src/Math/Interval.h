/**
 * @file Interval.h
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Definition of the Interval struct
 * @version 0.1
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

namespace Tracer
{
    struct Interval
    {
        float a,b;

        Interval(const float a, const float b);
        bool operator&&(const Interval& other) const;
        bool operator&&(const float other) const;
        Interval operator&(const Interval& other) const;
    };
}
