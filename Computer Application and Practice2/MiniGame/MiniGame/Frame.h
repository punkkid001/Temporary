#pragma once
#include<iostream>
#include<string>

using namespace std;

class Frame
{
public:
	int a, b;
	Frame()
	{

	}

	void* operator new(size_t size)
	{
		cout << "Allocation with new operator .." << endl;
		void *temp = malloc(size);

		if (!temp)
		{
			throw string("bad allocation");
		}
		return temp;
	}

	void* operator new[](size_t size)
	{
		cout << "Allocate with new[] operator .." << endl;
		void* temp = malloc(size);
		
		if (!temp)
		{
			throw string("bad allocation");
		}

		return temp;
	}

	void operator delete(void* addr)
	{
		cout << "Free with delete operator .." << endl;
		free(addr);
	}

	void operator delete[](void* addr)
	{
		cout << "Free with delete[] operator .." << endl;
		free(addr);
	}
};