#include <iostream>
#include "Orc.h"

Orc::Orc(string _Name)
{
	Name = _Name;
}

Orc::~Orc(){}

void Orc::render()
{
	cout << Name << " is an Orc." << endl;
}
