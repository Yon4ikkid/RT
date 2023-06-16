#include "Interval.h"

using namespace Tracer;

Interval::Interval(const float a, const float b) : a(a), b(b)
{
    if (this->a => this->b)
    {
        this->a = 0;
        this->b = 0;
    }
}

bool Interval::operator&&(const Interval& other) const
{
    Interval i = *this & other;
    return !(i.a == 0 && i.b == 0);
}

bool Interval::operator&&(const float other) const
{
    return other >= this->a && other <= this->b;
}

Interval Interval::operator&(const Interval& other) const
{
    return Interval(std::max(this->a, other.a), std::min(this->b, other.b));
}
