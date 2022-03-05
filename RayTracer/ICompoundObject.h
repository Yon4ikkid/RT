#pragma once

#include <vector>
#include "IObject.h"
#include "IRenderable.h"

class ICompoundObject : public IRenderable
{
private:
	std::vector<IObject*> __objects;

public:
	//
};
