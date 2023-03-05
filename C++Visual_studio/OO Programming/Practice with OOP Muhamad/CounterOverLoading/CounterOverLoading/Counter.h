#pragma once
#include"Counter.h"
using namespace std;

class Counter
{
private:
	unsigned int count;
public:
	int getCount();
	Counter();
    Counter(int c );
	~Counter();


	// unary operater  per fix important for overloading

	Counter operator ++()
	{
		++count;
		return Counter(count);
	}
	// unary operater  post fix important for overloading
	Counter operator ++(int)
	{
		++count;
		return Counter(count);
	}




	// with minus operator
	Counter operator --()
	{
		--count;
		return Counter(count);
	}
};

