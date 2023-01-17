#pragma once
#include <vector>
#include <mutex>

using namespace std;

class Inventory
{
	private:
		vector<int> Numbers;
		mutex InventoryMutex;

	public: 
		Inventory();
		Inventory(vector<int> _Numbers);

		int get();
		int getAt(int _Index);
		void put(int _Number);
		void putMultiple(vector<int> _Numbers);
		int size();
};

