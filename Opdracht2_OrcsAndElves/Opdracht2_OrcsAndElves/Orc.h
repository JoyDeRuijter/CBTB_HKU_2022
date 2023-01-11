#pragma once
#include "NPC.h"

class Orc : public NPC
{
	public:
		Orc(string _Name);
		virtual ~Orc();

		void render();
};
