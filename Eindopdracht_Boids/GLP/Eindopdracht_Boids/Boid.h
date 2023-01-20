#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Boid
{
	private:
		CircleShape BoidShape;
		void setRandomPosition();
		void setVelocity();

	public:
		Boid();
		Vector2f Position;
		Vector2f Velocity;
		CircleShape& getShape();
		void spawn();
		void update();
};

