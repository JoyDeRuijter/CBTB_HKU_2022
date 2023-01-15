#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "Inventory.h"

using namespace std;

mutex producerMu;
Inventory inventory;

void producer(int x)
{
    lock_guard<mutex> guard(producerMu);
    producerMu.lock();
    
    for(int i = 0; i < x; i++)
        inventory.put(i);

    producerMu.unlock();
}

void calculate()
{
    thread thread1(&producer, 10), thread2(&producer, 20);
    
    thread1.join();
    thread2.join();

    cout << "Inventory: " << endl;
    for(int i = 0; i < inventory.size(); i++)
    {
        cout << "Size: " << inventory.size() << ", First element: " << inventory.get() << endl;
    }

    thread1.detach();
    thread2.detach();
}


int main() 
{
    for (int i = 0; i < 100; i++)
        calculate();

    return 0;
}