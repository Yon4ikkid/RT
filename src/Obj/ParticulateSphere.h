#pragma once
#include "ISurface.h"

namespace Tracer
{
    class ParticulateSphere : public ISurface
    {
        private:
            Vector center;
            float radius;

        public:
            ParticulateSphere();
            ParticulateSphere(Vector center, float radius);

            std::optional<float> intersect(const Ray& r);
		    Vector get_normal(const Vector& p) const;
    };
}
