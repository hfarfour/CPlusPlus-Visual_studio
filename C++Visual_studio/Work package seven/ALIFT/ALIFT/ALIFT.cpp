// ALIFT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>         // middle class and newState are not running
#include <vector>
#include <iostream>
using namespace std;

enum state { TOP, BOTTON, MIDDLE };
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
	virtual bool up()
	{
		cout << "Error" << endl;
		return false;
	}
	virtual bool middle()
	{
		cout << "Error" << endl;
		return false;
	}
	virtual bool down()
	{
		cout << "Error" << endl;
		return false;
	}
};

class FloorState : public State, public Transition
{
public:
	FloorState(StateContext* Context) : State(Context) {}
};

class TopFloor : public FloorState
{
public:
	TopFloor(StateContext* Context) :FloorState(Context) {}
	virtual bool up()
	{
		cout << "Top floor , there is no up " << endl << endl;
		return false;
	}

	virtual bool middle()
	{
		cout << "Top floor , lift going to middle " << endl << endl;
		this->CurrentContext->setState(MIDDLE);
		return false;
	}

	virtual bool down()
	{
		cout << "top floor , going down " << endl << endl;
		this->CurrentContext->setState(BOTTON);
		return true;
	}
};
/// =======================================================//////////////////////
class MiddleFloor : public FloorState 
{
public:
	MiddleFloor(StateContext* Context) :FloorState(Context) {}
	virtual bool up()
	{
		cout << "Middle floor , going up " << endl << endl;
		this->CurrentContext->setState(TOP);
		return false;
	}
	virtual bool down()
	{
		cout << "middle floor , going down " << endl << endl;
		this->CurrentContext->setState(BOTTON);
		return true;
	}
};
//=======================================================================================

class BottonFloor : public FloorState
{
public:
	BottonFloor(StateContext* Context) : FloorState(Context) {}
	virtual bool up()
	{
		cout << "Botton floor , going up " << endl << endl;
		this->CurrentContext->setState(TOP);
		return false;
	}
	virtual bool middle()
	{
		cout << "Botton floor , the lift going middle " << endl << endl;
		this->CurrentContext->setState(MIDDLE);
		return true;
	}
	virtual bool down()
	{
		cout << "Botton floor , there is no down " << endl << endl;
		this->CurrentContext->setState(BOTTON);
		return true;
	}
};


class LiftShaft : public StateContext , public Transition
{
public:
	LiftShaft()
	{
		this->availableStates.push_back(new TopFloor(this));
		this->availableStates.push_back(new MiddleFloor(this));
		this->availableStates.push_back(new BottonFloor(this));
		this->setState(BOTTON);    // start state
	}
	bool up()
	{
		return ((FloorState*)this->CurrentState)->up();
	}
	bool middle()
	{
		return ((FloorState*)this->CurrentState)->middle();
	}

	bool down()
	{
		return ((FloorState*)this->CurrentState)->down();
	}

};




int main()
{
	int NumberOfFloors = 2;
	LiftShaft* MyLift = new LiftShaft();
	for (int upcount = 0; upcount< NumberOfFloors; upcount++)
	{
		MyLift->up();
	}
	for (int middlecount = 0; middlecount < NumberOfFloors; middlecount++)
	{
		MyLift->middle();
	}
	for (int downcount = 0; downcount < NumberOfFloors; downcount++)
	{
		MyLift->down();
	}
	delete MyLift;
	getchar();
	
	return 0;
}