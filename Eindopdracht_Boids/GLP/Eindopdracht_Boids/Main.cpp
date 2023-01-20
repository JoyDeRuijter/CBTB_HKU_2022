#pragma once
#include <SFML/Graphics.hpp>
#include "BoidSimulator.h"

using namespace sf;

int main()
{
	
	BoidSimulator boidSimulator;
	
	int windowWidth = 1536;
	int windowHeight = 864;
	RenderWindow window;
	window.create(VideoMode::VideoMode(windowWidth, windowHeight), "BOIDS EINDOPDRACHT - JOY DE RUIJTER");
	
	boidSimulator.Start();
	while(window.isOpen())
		boidSimulator.Update(window, windowWidth, windowHeight);

	return 0;
}