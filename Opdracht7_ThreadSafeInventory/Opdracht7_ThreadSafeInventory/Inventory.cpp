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
    InventoryMutex.lock();

    if (Numbers.size() <= 0)
    {
        InventoryMutex.unlock();
        return NULL;
    }
    else
    {
        int firstNumber = Numbers[0];
        InventoryMutex.unlock();
        return firstNumber;
    }
}

int Inventory::getAt(int _Index)
{
    InventoryMutex.lock();

    int askedNumber = Numbers.at(_Index);
    
    InventoryMutex.unlock();
    return askedNumber;
}

void Inventory::put(int _Number)
{
    InventoryMutex.lock();
    Numbers.push_back(_Number);
    InventoryMutex.unlock();
}

void Inventory::putMultiple(vector<int> _Numbers)
{
    InventoryMutex.lock();

    this_thread::sleep_for(chrono::milliseconds(500));

    for(int i = 0; i < _Numbers.size(); i++)
        Numbers.push_back(_Numbers[i]);

    InventoryMutex.unlock();
}

int Inventory::size()
{
    return Numbers.size();
}
