#include <iostream>
#include "Soldier.h"

Soldier::Soldier(NPC* _Npc) : RoleDecorator(_Npc) {}

Soldier::~Soldier() {}

void Soldier::render()
{
	RoleDecorator::render();
	cout << "They are a brave and skilled soldier." << endl;
}