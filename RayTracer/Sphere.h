#pragma once

#include "ISurfaceObject.h"

class Sphere : public ISurfaceObject
{
private:
	Vector __centre;
	float __radius;

public:
	Sphere();
	Sphere(const Vector& centre, const float radius);

	bool Intersect(const Ray& r, int rgb[3]) const override;
	Vector GetNormal(const Vector& p) const override;

	Vector GetCentre() const;
	float GetRadius() const;

	void SetCentre(const Vector& centre);
	void SetRadius(const float radius);
};
