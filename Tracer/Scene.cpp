#include "Scene.h"

Tracer::Scene::Scene()
{
}

Tracer::Scene::~Scene()
{
	for (auto i = sceneObjects.begin(); i != sceneObjects.end(); i++)
		delete (*i);
}
