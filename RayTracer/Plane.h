#pragma once

#include "ISurfaceObject.h"

class Plane : public ISurfaceObject
{
private:
	float __a;
	float __b;
	float __c;
	float __d;

public:
	Plane();
	Plane(const float a, const float b, const float c, const float d);
	Plane(const Vector& normal, const float d);
	Plane(const Vector& normal, const Vector& p);

	bool Intersect(const Ray& r, int rgb[3]) const override;
	Vector GetNormal(const Vector& p) const override;
};
