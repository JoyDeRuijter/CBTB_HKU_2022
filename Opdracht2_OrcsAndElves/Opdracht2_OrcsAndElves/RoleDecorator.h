#pragma once
#include "NPC.h"

class RoleDecorator : public NPC
{
	private:
		NPC* Npc;

	public:
		RoleDecorator(NPC* _Npc);
		virtual ~RoleDecorator();

		virtual void render();
};

