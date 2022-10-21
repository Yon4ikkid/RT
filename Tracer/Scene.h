#pragma once
#include <vector>

#include "Camera.h"
#include "IRenderable.h"

namespace Tracer
{
	struct Scene
	{
		std::vector<IRenderable*> sceneObjects;
		Camera* camera;
		// Add light sources etc.

		Scene();
		~Scene(); // Scene takes care of freeing the memory of the objects
	};
}
