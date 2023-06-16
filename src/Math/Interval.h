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
