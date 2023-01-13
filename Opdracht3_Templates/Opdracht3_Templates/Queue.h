#pragma once
#include <vector>
using namespace std;

template<typename T>
class Queue
{
	private:
		vector<T> ElementList;

	public:
		Queue(){}
		Queue(vector<T> _Elements)
		{
			ElementList = _Elements;
		}

		void put(T _Element)
		{
			ElementList.push_back(_Element);
		}
		T get()
		{
			if(ElementList.size() != 0)
				return ElementList.front();
			else
				return NULL;
		}
		int size()
		{
			return ElementList.size();
		}
};