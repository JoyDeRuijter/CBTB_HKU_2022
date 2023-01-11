#pragma once
#include "RoleDecorator.h"

class Shaman : public RoleDecorator
{	
	public:
		Shaman(NPC* _Npc);
		virtual ~Shaman();

		void render();
};

