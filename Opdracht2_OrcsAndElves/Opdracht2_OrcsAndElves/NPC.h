#pragma once
#include <string>
using namespace std;

class NPC
{
	protected:
		string Name;

	public:
		NPC();
		virtual ~NPC();

		virtual void render() = 0;
};

