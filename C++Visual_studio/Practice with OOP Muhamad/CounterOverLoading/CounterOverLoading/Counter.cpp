#include "Counter.h"

int Counter::getCount()
{
	return count;
}

Counter::Counter() :count(0)
{
}

Counter::Counter(int c):count(c)
{
}

Counter::~Counter()
{
}
