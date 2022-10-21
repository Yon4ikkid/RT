#pragma once
#include <thread>
#include <vector>

#include "Scene.h"
#include "Screen.h"

namespace Tracer
{
	class Renderer
	{
	private:
		int threadCount;
		Scene* renderScene;
		Screen* renderScreen;
		std::vector<std::thread> renderThreads;
		void renderLines(const int startingLine, const int endingLine);

	public:
		Renderer(const int threads, Scene* scene, Screen* screen);
		void render();
	};
}
