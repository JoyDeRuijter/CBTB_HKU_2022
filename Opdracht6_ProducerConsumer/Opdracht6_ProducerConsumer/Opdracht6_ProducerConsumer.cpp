#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace std;

int counter = 0;
bool done = false;

queue<int> goods;
mutex producerMu;
condition_variable cvConsumerWait;

void producer() {
    std::cout << "Starting producer..." << std::endl;

    for (int i = 0; i < 500; ++i)
    {
        unique_lock<mutex> ul(producerMu);
        if (goods.size() >= 5)
            cvConsumerWait.wait(ul, []() {return !(goods.size() >= 5);});

        goods.push(i);
        counter++;

        ul.unlock();
        cvConsumerWait.notify_one();
        
        cout << "Producer produced " << i << endl;
    }

    std::cout << "Finished producer..." << std::endl;
}

void consumer() {
    std::cout << "Starting consumer..." << std::endl;

    while (1) 
    {
        unique_lock<mutex> ul(producerMu);
        if (goods.empty())
            cvConsumerWait.wait(ul, []() {return !goods.empty(); });

        ul.unlock();
        int element = goods.front();
        goods.pop();
        counter--;
        cvConsumerWait.notify_one();

        cout << "Consumer consumed " << element << endl;

        if (element == 499)
        {
            done = true;
            std::cout << "Finished consumer..." << std::endl;
            return;
        }
    }
}

int main() {
    counter = 0;
    thread producerThread(producer);
    thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    if (done)
        std::cout << "Net: " << counter << " " << goods.size() << std::endl;

    while(1);
}
