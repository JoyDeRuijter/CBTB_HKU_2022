#include "Boid.h"
#include <iostream>

using namespace std;

Boid::Boid()
{
	BoidShape = CircleShape(25, 3);
	BoidShape.setFillColor(Color(44, 128, 138));
}

void Boid::setRandomPosition()
{
	cout << "setting random position" << endl;
	float x = (rand() % 1536) + 1;
	float y = (rand() % 864) + 1;
	Position.x = x;
	Position.y = y;
}

void Boid::setVelocity()
{
	Velocity.x = 0.2f;
	Velocity.y = 0.2f;
}

CircleShape& Boid::getShape()
{
	return BoidShape;
}

void Boid::spawn()
{
	setRandomPosition();
	setVelocity();
}

void Boid::update()
{
	BoidShape.setPosition(Position.x, Position.y);
}
