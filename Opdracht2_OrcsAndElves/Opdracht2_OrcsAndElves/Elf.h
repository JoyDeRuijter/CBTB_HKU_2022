#pragma once
#include <iostream>
#include "NPC.h"

class Elf: public NPC
{
	public:
		Elf(string _Name);
		virtual ~Elf();

		void render();
};

