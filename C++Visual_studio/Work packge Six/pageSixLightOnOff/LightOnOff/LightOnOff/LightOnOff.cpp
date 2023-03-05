// LightOnOff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// WorkpageSix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//===========================
// turorial question one
////=========================

//enum Doorstate { OPEN , CLOSED };
//string DoorDescription[] = { "Open","Closed" };
//
//class Door
//{
//private:
//    Doorstate currentState = CLOSED;
//public:
//    void open()
//    {
//        if (this->currentState == CLOSED)
//        {
//            this->currentState = OPEN;
//            cout << "The Door is now   " << DoorDescription[this->currentState] << endl;
//        }
//
//    }
//    void close()
//    {
//        if (this->currentState == OPEN)
//        {
//            this->currentState = CLOSED;
//            cout << "The Door is now    " << DoorDescription[this->currentState] << endl;
//        }
//
//    }
//};
//int main()
//{
//    Door MyDoor;
//    MyDoor.close();  //not doing anything becasue the door is already closed/
//    MyDoor.open();
//   MyDoor.close();
//}
//


//=====================
//tutorial qoestion two
//=====================


//class SimpleLightSwitch
//{
//private:
//	int currentLightstate = OFF;
//public:
//	void pressbutton()
//	{
//		if (currentLightstate == OFF)
//		{
//			cout << "Light going on .. " << endl;
//			currentLightstate = ON;
//		}
//		else
//		{
//			cout << "Light going on.." << endl;
//			currentLightstate = OFF;
//		}
//		for (int count = 0; count < 10; count++)
//		{
//			MyLightSwitch.pressButton();
//		}
//	}
//};
//class StateContext;
//class State
//{
//protected:
//	StateContext* CurrentContext;
//public:
//	State(StateContext* Context)
//	{
//		CurrentContext = Context;
//	}
//	virtual ~State() {}
//};
//
//class StateContext
//{
//protected:
//	State* CurrentState = nullptr;
//	int stateIndex = 0;
//	vector<State*> availableStates;
//public:
//	virtual ~StateContext()
//	{
//		for (int count = 0; count < this->availableStates.size(); count++)
//		{
//			delete this->availableStates[count];
//		}
//	}
//	virtual void setState(state newState)
//	{
//		this->CurrentState = availableStates[newState];
//		this->stateIndex = newState;
//	}
//	virtual int getStateIndex()
//	{
//		return this->stateIndex;
//	}
//
//};
//
//
//class Transition
//{
//public:
//	virtual void pressButton()
//	{
//		cout << "Error" << endl;
//	}
//};
enum state { ON, OFF };
class LightSwitchState //: public State , public Transition
{
public:
	//LightSwitchState(StateContext* CurrentContext) : State(CurrentContext) {}
	virtual void pressButton() {}
};

class LightSwitchOn : public LightSwitchState
{
public:
	//LightSwitchOn(StateContext* CurrentContext) : LightSwitchState(CurrentContext) {}
	void pressButton()
	{
		cout << "Light going OFF" << endl;
		//this->CurrentContext->setState(OFF);
	}
};

class LightSwitchOff : public LightSwitchState
{
public:
	//LightSwitchOff(StateContext* CurrentContext) : LightSwitchState(CurrentContext) {}
	void pressButton()
	{
		cout << "Light going ON" << endl;
		//this->CurrentContext->setState(ON);
	}
};

class LightSwitch //: public StateContext , public Transition
{
protected:
	//LightSwitchState* currentLightSwitchstate = nullptr;
	state currentLightSwitchstate = OFF;
	vector<LightSwitchState*> availableStates;
public:
	LightSwitch()
	{
		this->availableStates.push_back(new LightSwitchOn);
		this->availableStates.push_back(new LightSwitchOff);
		//this->setState(OFF);
	}
	~LightSwitch()
	{
		for (int count = 0; count < this->availableStates.size(); count++)
		{
			delete this->availableStates[count];
		}
	}
	void pressButton()
	{
		if (currentLightSwitchstate == OFF)
		{
			currentLightSwitchstate = ON;
		}
		else
			currentLightSwitchstate = OFF;

		availableStates[currentLightSwitchstate]->pressButton();
		//currentLightSwitchstate = (LightSwitchState*) CurrentState;
		//currentLightSwitchstate->pressButton();
	}

};




int main()
{
	LightSwitch MyLightswitch;
	for (int count = 0; count < 3; count++)
	{
		MyLightswitch.pressButton();
	}
	return 0;
}