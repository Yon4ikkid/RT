#pragma once

#include "IObject.h"

class ISurfaceObject : public IObject
{
public:
	virtual Vector GetNormal(const Vector& p) const = 0;
};
