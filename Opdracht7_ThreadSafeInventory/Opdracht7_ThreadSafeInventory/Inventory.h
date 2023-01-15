#pragma once
#include <vector>

using namespace std;

class Inventory
{
	private:
		vector<int> Numbers;

	public: 
		Inventory();
		Inventory(vector<int> _Numbers);

		int get();
		void put(int _Number);
		int size();
};

