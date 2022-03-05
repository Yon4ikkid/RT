#pragma once

#include "Vector.h"

class Ray
{
private:
	Vector __origin;
	Vector __direction;
	int __distance_limit;

public:
	Ray();
	Ray(const Vector& origin, const Vector& direction);
	Ray(const Vector& origin, const Vector& direction, const int distance_limit);

	void SetOrigin(const Vector& origin);
	void SetDirection(const Vector& direction);
	void SetDistanceLimit(const int distance_limit);

	int GetDistanceLimit() const;
	Vector GetOrigin() const;
	Vector GetDirection() const;
};
