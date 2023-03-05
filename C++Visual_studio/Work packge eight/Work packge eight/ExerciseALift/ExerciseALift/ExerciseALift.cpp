// LightOnOff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// WorkpageSix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;


enum state { Out_Of_Chocolate, No_Credit, Has_Credit, Dispenses_Chocolate };
enum stateParameter { No_Of_Chocolates, Credit };

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
	virtual void transition() {}
};

class StateContext
{
protected:
	State* CurrentState = nullptr;
	int stateIndex = 0;
	vector<State*> availableStates;
	vector<int>StateParameters;
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
		this->CurrentState->transition();
	}
	virtual int getStateIndex()
	{
		return this->stateIndex;
	}
	virtual void setStatePram(stateParameter SP,int value)
	{
		this->StateParameters[SP] = value;
	}
	virtual int getStateParam(stateParameter SP)
	{
		return this->StateParameters[SP];
	}
};


class Transition
{
public:
	virtual bool insertMoney(int)
	{
		cout << "Error" << endl;
		return false;
	}
	virtual bool makeSelection(int)
	{
		cout << "Error" << endl;
		return false;
	}
	virtual bool moneyRejected()
	{
		cout << "Error" << endl;
		return false;
	}
	virtual bool addChocolate(int)
	{
		cout << "Error" << endl;
		return false;
	}
	virtual bool dispense()
	{
		cout << "Error" << endl;
		return false;
	}
};



class ChocoState : public State, public Transition
{
public:
	ChocoState(StateContext* Context) :State(Context)
	{
	}
};

class OutOfChocolate : public ChocoState
{
public:
	OutOfChocolate(StateContext* Context) : ChocoState(Context) {}
	bool insertMoney(int money)
	{
	}
	bool makeSelection(int option)
	{
		cout << "Error ! No chocolates left ! no Selection made " << endl;
		return false;
	}
	bool moneyRejected()
	{
		cout << "Rejected ! " << endl;
		this->CurrentContext->setStatePram(Credit, 0);
		this->CurrentContext->setState(Out_Of_Chocolate);
		return true;
	}
	bool addChocolate(int number)
	{
		this->CurrentContext->setStatePram(No_Of_Chocolates,number);
		this->CurrentContext->setState(No_Credit);
		return true;
	}
	bool dispense()
	{
		cout << "Error ! No chocolates left ! no thing to dispense " << endl;
		return false;
	}
};

class NoCredit : public ChocoState
{
public:
	NoCredit(StateContext* Context) : ChocoState(Context) {}
	bool insertMoney(int money)
	{
		cout << "You inserted ! " << endl;
		this->CurrentContext->setStatePram(Credit, money);
		cout << "TOTAL : " << money <<endl;
		this->CurrentContext->setState(Has_Credit);
		return true;
	}
	bool makeSelection(int option)
	{
		cout << "Error ! No Money  " << endl;
		return false;
	}
	bool moneyRejected()
	{
		cout << "Error ! Money Rejected  " << endl;
		return false;
	}
	bool addChocolate(int number)
	{
		cout << "Error ! Already Got Chocolate " << endl;
		return false;
	}
	bool dispense()
	{
		cout << "Error ! No Money  " << endl;
		return false;
	}
};
class HasCredit  : public ChocoState
{
public:
	HasCredit(StateContext* Context) : ChocoState(Context) {}
	bool insertMoney(int money)
	{
		cout << "You inserted ! " <<money<< endl;
		money = money + this->CurrentContext->getStateParam(Credit);
		this->CurrentContext->setStatePram(Credit, money);
		cout << "TOTAL : " << money << endl;
		this->CurrentContext->setState(Has_Credit);
		return true;
	}
	bool makeSelection(int option)
	{
		cout << "Selectin made  " << endl;// specific selection not made yet
		if (!((chocolate_Dispenser*)this->CurrentContext)->itemRetrived)
		{
			delete ((chocolate_Dispenser*)this->CurrentContext)->DispenseItem;
			// delete product if one was created , but not retrived
		}
		((chocolate_Dispenser*)this->CurrentContext)->DispenseItem = new Chocolate;
		((chocolate_Dispenser*)this->CurrentContext)->itemRetrived = false;
		//need to factor in pricing here
		this->CurrentContext->setState(Dispenses_Chocolate);
		return true;
	}
	bool moneyRejected()
	{
		cout << "Error ! Money Rejected  " << endl;
		this->CurrentContext->setStatePram(Credit, 0);
		this->CurrentContext->setState(No_Credit);
		return true;
	}
	bool addChocolate(int number)
	{
		cout << "Error ! Already Got Chocolate " << endl;
		return false;
	}
	bool dispense()
	{
		cout << "Error ! No Money  " << endl;
		return false;
	}
};
class DispensesChocolate : public ChocoState
{
public:
	DispensesChocolate(StateContext* Context) : ChocoState(Context) {}
	bool insertMoney(int money)
	{
		cout << "busy Dispensing  " << endl;
		return false;
	}
	bool makeSelection(int option)
	{
		cout << "Error ! busy Dispensing" << endl;
		return false;
	}
	bool moneyRejected()
	{
		cout << "Error ! busy Dispensing " << endl;
		return false;
	}
	bool addChocolate(int number)
	{
		cout << "Error ! busy Dispensing  " << endl;
		return false;
	}
	bool dispense()
	{
		if (this->CurrentContext->getStateParam(Credit) >= ((chocolate_Dispenser*)this->CurrentContext)->DispenseItem->cost())
		{
			cout << "Dispensing ! "<<endl;
			this->CurrentContext->setStatePram(Credit, this->CurrentContext->getStateParam(Credit)- ((chocolate_Dispenser*)this->CurrentContext)->DispenseItem->cost());
			this->CurrentContext->setStatePram(No_Of_Chocolates, this->CurrentContext->getStateParam(No_Of_Chocolates) - 1);
			((chocolate_Dispenser*)this->CurrentContext)->itemDispensed = true;
		}
		else
		{
			cout << "Error ! no enough money  " << endl;
		}

		if (this->CurrentContext->getStateParam(Credit) > 0)
		{
			this->CurrentContext->setState(Has_Credit);
		}
		else
		{
			this->CurrentContext->setState(No_Credit);
		}

		if (this->CurrentContext->getStateParam(No_Of_Chocolates) == 0)
		{
			this->CurrentContext->setState(Out_Of_Chocolate);
		}
		else
		{
			this->CurrentContext->setState(No_Credit);
		}
		return true;
	}
};
class product
{
protected:
	string product_description;
	int itemCost = 0;
public:
	virtual int cost()
	{
		return this->itemCost;
	}
	virtual string description()
	{
		return this->product_description;
	}

};
class Chocolate : public product
{
public:
	Chocolate()
	{
		this->product_description = "Chocolate";
		this->itemCost = 50;
	}
};
class chocolate_Dispenser :public StateContext, public Transition
{
	friend class DispensesChocolate;
	friend class HasCredit;
private:
	ChocoState* ChocoCurrentState = nullptr;
	bool itemDispensed = false; // indicate whether a product is there to be retrived
	product* DispenseItem = nullptr;
	bool itemRetrived = false; // indicate whether a product has been retrived
public:
	chocolate_Dispenser(int inventory_count)
	{
		this->availableStates.push_back(new OutOfChocolate(this));
		this->availableStates.push_back(new NoCredit(this));
		this->availableStates.push_back(new HasCredit(this));
		this->availableStates.push_back(new DispensesChocolate(this));
		this->StateParameters.push_back(0);// no of Chocolate
		this->StateParameters.push_back(0);// available credit

		this->setState(Out_Of_Chocolate);
		if (inventory_count > 0)
		{
			this->addChocolate(inventory_count);
		}
	}
	~chocolate_Dispenser()
	{
		if (!this->itemRetrived)
		{
			delete this->DispenseItem;
		}
	}
	bool insertMoney(int money)
	{
		ChocoCurrentState =(ChocoState* )this->CurrentState;
		return this->ChocoCurrentState->insertMoney(money);
	}
	bool makeSelection(int option)
	{
		ChocoCurrentState = (ChocoState*)this->CurrentState;
		return this->ChocoCurrentState->makeSelection(option);
	}
	bool moneyRejected()
	{
		ChocoCurrentState = (ChocoState*)this->CurrentState;
		return this->ChocoCurrentState->moneyRejected();
	}
	bool addChocolate(int number)
	{
		ChocoCurrentState = (ChocoState*)this->CurrentState;
		return this->ChocoCurrentState->addChocolate(number);
	}
	bool dispense()
	{
		ChocoCurrentState = (ChocoState*)this->CurrentState;
		return this->ChocoCurrentState->dispense();
	}
	product* getProduct()
	{
		if (this->itemDispensed)
		{
			this->itemDispensed = false;
			this->itemRetrived = true;
			 return this->DispenseItem ;
		}
		return nullptr;
	}
};

int main()
{
	cout << "hello" << endl;
	return 0;
}