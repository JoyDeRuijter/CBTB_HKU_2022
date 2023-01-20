#include "BoidSimulator.h"

BoidSimulator::BoidSimulator()
{
	NumberOfBoids = 30;
	SharedVelocityPerFrame = 1;
	BoidDistance = 50;
	SeperationForce = 100.0f;
	MassPerFrame = 10;
	MaxBoidSpeed = 0.2f;
}

void BoidSimulator::Start()
{
    SpawnBoids();
}

void BoidSimulator::Update(RenderWindow& _Window, int _WindowWidth, int _WindowHeight)
{
    MoveBoids(_WindowWidth, _WindowHeight);
    Draw(_Window);
}

void BoidSimulator::Draw(RenderWindow& _Window)
{
    _Window.clear(Color(44, 81, 84));
    for (int i = 0; i < Boids.size(); i++)
        _Window.draw(Boids[i]->getShape());

    _Window.display();
}

void BoidSimulator::SpawnBoids()
{
    for (int i = 0; i < NumberOfBoids; i++) {
        Boid* boid = new Boid();
        Boids.push_back(boid);
        boid->spawn();
    }
}

void BoidSimulator::MoveBoids(int _WindowWidth, int _WindowHeight)
{ 
    for (Boid* b : Boids)
    {
        b->Velocity += CenterOfMass(b) +SeperationValue(b) + MatchVelocity(b) + ConformToBounds(b, _WindowWidth, _WindowHeight);

        if (sqrt((b->Velocity.x * b->Velocity.x) + (b->Velocity.y * b->Velocity.y)) > 0.2f)
            b->Velocity = ((b->Velocity / sqrt((b->Velocity.x * b->Velocity.x) + (b->Velocity.y * b->Velocity.y))) * MaxBoidSpeed);

        b->Position = b->Position + b->Velocity;
    }

    for (int i = 0; i < Boids.size(); i++)
        Boids[i]->update();
}

Vector2f BoidSimulator::CenterOfMass(Boid* _B)
{
    Vector2f vector;

    for (Boid* b : Boids)
    {
        if (b != _B)
            vector += b->Position;
    }
    vector /= (float)(NumberOfBoids - 1);
    return (vector - _B->Position) / MassPerFrame;
}

Vector2f BoidSimulator::SeperationValue(Boid* _B)
{
    Vector2f vector;

    for (Boid* b : Boids)
    {
        if (b != _B) {
            if (Distance(_B->Position, _B->Position) < BoidDistance)
                vector += _B->Position - _B->Position;
        }
    }
    return vector / SeperationForce;
}

Vector2f BoidSimulator::MatchVelocity(Boid* _B)
{
    Vector2f vector;

    for (Boid* b : Boids)
    {
        if (b != _B)
            vector += b->Velocity;
    }
    vector /= (float)(NumberOfBoids - 1);
    return (vector - _B->Velocity) / SharedVelocityPerFrame;
}

Vector2f BoidSimulator::ConformToBounds(Boid* _B, int _WindowWidth, int _WindowHeight)
{
    Vector2f vector;
    if (_B->Position.x < 0) 
        vector.x = 0;
    else if (_B->Position.x > _WindowWidth) 
        vector.x = _WindowWidth;
    if (_B->Position.y < 0) 
        vector.y = 0;
    else if (_B->Position.y > _WindowHeight) 
        vector.y = _WindowHeight;

    return vector;
}

float BoidSimulator::Distance(Vector2f _A, Vector2f _B)
{
    return sqrt(pow(_B.x - _A.x, 2) + pow(_B.y - _A.y, 2) * 1.0);
}
