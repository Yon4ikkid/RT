#pragma once
#include "Ray.h"
#include "material.h"
#include "IRenderable.h"

class IObject : public IRenderable
{
private:
	Material __objectMaterial;

public:
	IObject(const Material& objectMaterial);
};
