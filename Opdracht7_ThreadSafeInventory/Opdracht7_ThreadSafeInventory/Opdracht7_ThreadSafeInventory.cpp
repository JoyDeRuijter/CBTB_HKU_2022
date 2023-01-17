#include <iostream>
#include <vector>
#include <thread>
#include "Inventory.h"

using namespace std;

auto *inventory =  new Inventory();
vector<int> firstSequence = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> secondSequence = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

void calculate()
{
    thread thread1(&Inventory::putMultiple, inventory, firstSequence);
    thread thread2(&Inventory::putMultiple, inventory, secondSequence);

    thread1.join();
    thread2.join();

    cout << "Inventory: " << endl;
    cout << "Size: " << inventory->size() << ", First element: " << inventory->get() << endl;
    for (int i = 0; i < inventory->size(); i++)
        cout << "At index " << i << ": " << inventory->getAt(i) << endl;
}


int main() 
{
    calculate();

    delete inventory;

    return 0;
}