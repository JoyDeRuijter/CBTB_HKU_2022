#include <iostream>
#include <vector>
#include "Elf.h"
#include "Orc.h"
#include "Farmer.h"
#include "Soldier.h"
#include "Shaman.h"

using namespace std;

int main()
{
	NPC* Npc1 = new Soldier(new Elf("Legolas"));
	NPC* Npc2 = new Farmer(new Soldier(new Elf("Galadriel")));
	NPC* Npc3 = new Elf("Buddy");
	NPC* Npc4 = new Soldier(new Orc("Azog"));
	NPC* Npc5 = new Shaman(new Orc("Brine"));

	vector<NPC*> NPCs = {Npc1, Npc2, Npc3, Npc4, Npc5};

	for (int i = 0; i < NPCs.size(); i++)
	{
		NPCs[i]->render();
		cout << "" << endl;
		delete NPCs[i];
	}
}