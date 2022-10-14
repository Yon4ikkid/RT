#pragma once
#include "ISurface.h"
#include "Vector.h"


namespace Tracer
{
	class Sphere : public ISurface
	{
	private:
		Vector __c;
		float __r;

	protected:
		Vector getNormal(const Vector& p) const override;

	public:
		Sphere(const Vector& center, const float radius, const Material& material);
		bool intersect(const Ray& r, Intersection& out) override;
	};
}
