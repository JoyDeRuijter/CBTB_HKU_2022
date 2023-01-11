#include <iostream>
#include "Elf.h"
#include "Orc.h"
#include "Farmer.h"
#include "Soldier.h"
#include "Shaman.h"
#include <vector>

using namespace std;

int main()
{
	NPC Npc1 = Elf("Legolas");
	//if (Npc1.Name == "")
	//	cout << "Npc1 name is empty string" << endl;
	//else
	//	cout << Npc1.Name << endl;
	Npc1 = Farmer(Npc1);
	//cout << Npc1.Name << endl;

	//if (Npc1.Name == "")
	//	cout << "Npc1 name is empty string" << endl;

	NPC Npc2 = Elf("Galadriel");
	Npc2 = Farmer(Npc2);
	Npc2 = Soldier(Npc2);

	NPC Npc3 = Elf("Buddy");
	
	NPC Npc4 = Orc("Azog");
	Npc4 = Soldier(Npc4);

	NPC Npc5 = Orc("Brine");
	Npc5 = Shaman(Npc5);

	vector<NPC> NPCs = {Npc1, Npc2, Npc3, Npc4, Npc5};

	for (int i = 0; i < NPCs.size(); i++)
		NPCs[i].render();
}