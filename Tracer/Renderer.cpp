#include <iostream>

#include "Renderer.h"
#include "Ray.h"

void Tracer::Renderer::renderLines(const int startingLine, const int endingLine)
{
	Ray r;
	Intersection in;

	for (int line = startingLine; line <= endingLine; line++)
		for (int column = 1; column <= this->renderScreen->GetWidth(); column++)
		{
			r = this->renderScene->camera->getRay(line, column);
			for (int i = 0; i < this->renderScene->sceneObjects.size(); i++)
			{
				if (this->renderScene->sceneObjects[i]->intersect(r, in))
				{
					this->renderScreen->set(column - 1, line - 1, in.m.color);
				}
			}
		}
}

Tracer::Renderer::Renderer(const int threads, Scene* scene, Screen* screen) : threadCount(threads), renderScene(scene), renderScreen(screen) { }

void Tracer::Renderer::render()
{
	std::vector<std::pair<int, int>> segments;
	int lines = this->renderScreen->GetHeight(), a, b, linesPerThread = lines / this->threadCount;
	std::cout << "Lines per thread: " << linesPerThread << '\n';

	a = 1;
	b = linesPerThread;
	// Calculate line divisions
	for (int i = 0; i < this->threadCount; i++)
	{
		std::cout << "Thread " << i << " lines: " << a << " - " << b << '\n';
		segments.push_back(std::pair<int, int>(a, b));
		a += linesPerThread;
		b += linesPerThread;
		lines -= linesPerThread;
	}

	// Account for leftover lines
	if (lines != 0)
		segments.back().second += lines;

	// Create threads
	for (int i = 0; i < this->threadCount; i++)
		this->renderThreads.push_back(std::thread(&Renderer::renderLines, this, segments[i].first, segments[i].second));

	// Wait for all threads to finish
	for (int i = 0; i < this->threadCount; i++)
		this->renderThreads[i].join();
}
