// WorkPageSixLight2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// WorkpageSix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum state { ACCEPTING, REJECTING };
class StateContext;
class State
{
protected:
	StateContext* CurrentContext;
public:
	State(StateContext* Context)
	{
		CurrentContext = Context;
	}
	virtual ~State() {}
};

class StateContext
{
protected:
	State* CurrentState = nullptr;
	int stateIndex = 0;
	vector<State*> availableStates;
public:
	virtual ~StateContext()
	{
		for (int count = 0; count < this->availableStates.size(); count++)
		{
			delete this->availableStates[count];
		}
	}
	virtual void setState(state newState)
	{
		this->CurrentState = availableStates[newState];
		this->stateIndex = newState;
	}
	virtual int getStateIndex()
	{
		return this->stateIndex;
	}

};


class Transition
{
public:
	virtual bool _(int value) 
	{
		cout << "Error" << endl;
		return false;
	}
};

class ARState : public State, public Transition
{
public:
	ARState(StateContext* Context) : State(Context) {}
};

class Accepting: public ARState
{
public:
	Accepting(StateContext* Context) :ARState(Context) {}
	bool _(int value)
	{
		if (value == 1)
			this->CurrentContext->setState(REJECTING);
		else
			this->CurrentContext->setState(ACCEPTING);
		return value;
	}
};

class Rejecting : public ARState
{
public:
	Rejecting(StateContext* Context) : ARState(Context) {}
	bool _(int value)
	{
		if (value == 1)
			this->CurrentContext->setState(ACCEPTING);
		else
			this->CurrentContext->setState(REJECTING);
		return value;
	}
};

class AcceptingEventNumberOnes : public StateContext, public Transition
{
public:
	AcceptingEventNumberOnes()
	{
		this->availableStates.push_back(new Accepting(this));
		this->availableStates.push_back(new Rejecting(this));
		this->setState(ACCEPTING);    // start state
	}

	bool _(int value)
	{
		return ((ARState*)this->CurrentState)->_(value);
	}
};




int main()
{
	vector<int> zerones = { 1,0,1,1 };
	AcceptingEventNumberOnes FiniteStateAutomate;
	for (int count = 0; zerones.size(); count++)
	{
		FiniteStateAutomate._(zerones[count]);
	}
	if (FiniteStateAutomate.getStateIndex() == ACCEPTING)
	{
		cout << "Accepted ! " << endl;
	}
	else
		cout << "Rejected ! " << endl;

	return 0;
}