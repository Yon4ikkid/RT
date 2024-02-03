/**
 * @file Scene.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Provides implementation for the Scene class
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Scene.h"

Tracer::Scene::Scene()
{
	
}

Tracer::Scene::~Scene()
{
	for (auto i = sceneObjects.begin(); i != sceneObjects.end(); i++)
		delete (*i);
	delete lightSource;
}
