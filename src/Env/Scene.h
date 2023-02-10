/**
 * @file Scene.h
 * @author Yon Kidalov
 * @brief Defines the Scene class
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <vector>

#include "Camera.h"
#include "../Render/IRenderable.h"

namespace Tracer
{
	struct Scene
	{
		std::vector<IRenderable*> sceneObjects;
		Camera camera;
		// Add light sources etc.

		Scene();
		~Scene(); // Scene takes care of freeing the memory of the objects
	};
}
