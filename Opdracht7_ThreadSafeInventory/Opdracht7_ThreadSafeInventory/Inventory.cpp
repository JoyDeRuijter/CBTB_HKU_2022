#include "Inventory.h"

Inventory::Inventory()
{
    Numbers = {};
}

Inventory::Inventory(vector<int> _Numbers)
{
    Numbers = _Numbers;
}

int Inventory::get()
{
    if (Numbers.size() <= 0)
        return NULL;
    else
    {
        int firstNumber = Numbers[0];
        Numbers.erase(Numbers.begin());
        return firstNumber;
    }

}

void Inventory::put(int _Number)
{
    Numbers.push_back(_Number);
}

int Inventory::size()
{
    return Numbers.size();
}
