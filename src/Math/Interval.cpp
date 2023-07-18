/**
 * @file Interval.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Implementation for the Interval struct
 * @version 0.1
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Interval.h"
#include <algorithm>

using namespace Tracer;

/**
 * @brief Construct a new Interval:: Interval object
 * 
 * @param a - lower bound
 * @param b - upper bound
 */
Interval::Interval(const float a, const float b) : a(a), b(b)
{
    if (this->a >= this->b)
    {
        this->a = 0;
        this->b = 0;
    }
}

/**
 * @brief Checks whether the intervals intersect
 * 
 * @param other - another interval
 * @return true - intersect
 * @return false - do not intersect
 */
bool Interval::operator&&(const Interval& other) const
{
    Interval i = *this & other;
    return !(i.a == 0 && i.b == 0);
}

/**
 * @brief Checks if a float is in the interval (practically an intersection)
 * 
 * @param other - a float value
 * @return true - contained
 * @return false - uncontained
 */
bool Interval::operator&&(const float other) const
{
    return other >= this->a && other <= this->b;
}

/**
 * @brief Conbines two intervals (returning their intersection)
 * 
 * @param other - another interval
 * @return Interval - intersection ([0,0] if no intersection is available)
 */
Interval Interval::operator&(const Interval& other) const
{
    return Interval(std::max(this->a, other.a), std::min(this->b, other.b));
}
