#pragma once
#include "RoleDecorator.h"
#include "NPC.h"

class Farmer : public RoleDecorator
{
	public:
		Farmer(NPC* _Npc);
		virtual ~Farmer();

		void render();
};

