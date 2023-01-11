#include <iostream>
#include "Farmer.h"

Farmer::Farmer(NPC _Npc)
{
	Npc = _Npc;
	Npc.Name += " - farmer -";
}
