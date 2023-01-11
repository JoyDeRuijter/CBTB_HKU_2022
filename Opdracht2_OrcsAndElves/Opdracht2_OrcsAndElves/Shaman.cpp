#include <iostream>
#include "Shaman.h"

Shaman::Shaman(NPC* _Npc) : RoleDecorator(_Npc) {}

Shaman::~Shaman() {}

void Shaman::render()
{
	RoleDecorator::render();
	cout << "They are a well respected shaman." << endl;
}