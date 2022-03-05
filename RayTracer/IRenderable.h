#pragma once

class IRenderable
{
public:
	virtual bool Intersect(const Ray& r, int rgb[3]) const = 0;
};
