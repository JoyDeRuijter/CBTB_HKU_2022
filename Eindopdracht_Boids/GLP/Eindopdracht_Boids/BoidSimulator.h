#pragma once
#include <SFML/Graphics.hpp>
#include "Boid.h"
#include <vector>

using namespace sf;
using namespace std;

class BoidSimulator
{
	private: 
		vector<Boid*> Boids;
		int NumberOfBoids;
		float SharedVelocityPerFrame;
		float BoidDistance;
		float SeperationForce;
		float MassPerFrame;
		float MaxBoidSpeed;

		
	public:
		BoidSimulator();
		
		void Start();
		void Update(RenderWindow& _Window, int _WindowWidth, int _WindowHeight);
		void Draw(RenderWindow& _Window);
		void SpawnBoids();
		void MoveBoids(int _WindowWidth, int _WindowHeight);

		Vector2f CenterOfMass(Boid* _Boid);
		Vector2f SeperationValue(Boid* _Boid);
		Vector2f MatchVelocity(Boid* _Boid);
		Vector2f ConformToBounds(Boid* _Boid, int _WindowWidth, int _WindowHeight);
		float Distance(Vector2f _A, Vector2f _B);
};

