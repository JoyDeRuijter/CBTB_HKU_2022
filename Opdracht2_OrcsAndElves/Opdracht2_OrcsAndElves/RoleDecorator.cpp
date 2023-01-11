#include "RoleDecorator.h"

RoleDecorator::RoleDecorator(NPC* _Npc)
{
	Npc = _Npc;
}

RoleDecorator::~RoleDecorator()
{
	if (Npc)
		delete Npc;
}

void RoleDecorator::render()
{
	Npc->render();
}
