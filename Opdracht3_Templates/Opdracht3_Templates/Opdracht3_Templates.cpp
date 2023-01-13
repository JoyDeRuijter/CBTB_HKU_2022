#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Queue.h"

using namespace std;

//Template function
template<typename T>
void sortSmallToBig(T _Array[], int _ArraySize)
{
	sort(_Array, _Array + _ArraySize);
}

int main()
{
	//The proof that shows that the template function works for both float and string arrays:
	float floatArray[] = {3.0f, 4.5f, 1.3f, 8.1f, 2.4f};
	string stringArray[] = {"elephant", "ant", "monkey", "bear", "dog", "crocodile"};

	cout << "THE FLOAT ARRAY BEFORE: ";
	for(int i = 0; i < size(floatArray); i++)
			cout << floatArray[i] << ", ";
	cout << endl;
	sortSmallToBig(floatArray, size(floatArray));
	cout << "USED THE SORT FUNCTION..." << endl;
	cout << "THE FLOAT ARRAY AFTER: ";
	for (int i = 0; i < size(floatArray); i++)
		cout << floatArray[i] << ", ";

	cout << endl;
	cout << endl;
	cout << "THE STRING ARRAY BEFORE: ";
	for (int i = 0; i < size(stringArray); i++)
		cout << stringArray[i] << ", ";
	cout << endl;
	sortSmallToBig(stringArray, size(stringArray));
	cout << "USED THE SORT FUNCTION..." << endl;
	cout << "THE FLOAT ARRAY AFTER: ";
	for (int i = 0; i < size(stringArray); i++)
		cout << stringArray[i] << ", ";

	cout << endl;
	cout << endl;
	cout << endl;

	//The proof that shows that the template class Queue works like it is supposed to do:
	vector<string> listOfColors = { "red", "blue", "yellow", "purple", "black", "white" };
	
	Queue<int> emptyIntQueue = Queue<int>();
	Queue<string> filledStringQueue = Queue<string>(listOfColors);

	cout << "CREATED AN EMPTY QUEUE OF TYPE INT CALLED 'QUEUE1'" << endl;
	cout << "QUEUE1.SIZE() = " << emptyIntQueue.size() << endl;
	cout << "QUEUE1.GET() = " << emptyIntQueue.get() << endl;
	cout << "QUEUE1.PUT(8);" << endl;
	emptyIntQueue.put(8);
	cout << "QUEUE1.SIZE() = " << emptyIntQueue.size() << endl;
	cout << "QUEUE1.GET() = " << emptyIntQueue.get() << endl;
	cout << endl;

	cout << "CREATED A NEW QUEUE THAT WAS FILLED WITH A LIST OF COLORS AS STRINGS CALLED 'QUEUE2'" << endl;
	cout << "QUEUE2.SIZE() = " << filledStringQueue.size() << endl;
	cout << "QUEUE2.GET() = " << filledStringQueue.get() << endl;
	cout << "QUEUE2.PUT('green');" << endl;
	filledStringQueue.put("green");
	cout << "QUEUE2.SIZE() = " << filledStringQueue.size() << endl;
	cout << "QUEUE2.GET() = " << filledStringQueue.get() << endl;
}