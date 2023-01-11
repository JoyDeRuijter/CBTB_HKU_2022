#include <iostream>
#include "Farmer.h"

Farmer::Farmer(NPC* _Npc) : RoleDecorator(_Npc){}

Farmer::~Farmer(){}

void Farmer::render()
{
	RoleDecorator::render();
	cout << "They are a hard working farmer." << endl;
}
