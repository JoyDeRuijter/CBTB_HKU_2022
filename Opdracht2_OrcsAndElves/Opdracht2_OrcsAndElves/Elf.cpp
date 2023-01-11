#include "Elf.h"

Elf::Elf(string _Name)
{
	Name = _Name;
}

Elf::~Elf(){}

void Elf::render()
{
	cout << Name << " is of Elvenkind." << endl;
}
