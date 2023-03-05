// CoursworkTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;


enum state { NO_NPCS, NO_RESOURCES, HAVE_RESOURCES, SPAWN_NPC };
enum stateParameter { NPCS, RESOURCES };

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
	virtual ~State(void)
	{
	}

};

class StateContext
{
protected:

	State* CurrentState = nullptr;
	int stateIndex = 0;
	vector<State*> availableStates;
	vector<int> stateParameters;

public:

	virtual ~StateContext()
	{
		for (int index = 0; index < this->availableStates.size(); index++) delete this->availableStates[index];
		this->availableStates.clear();
		this->stateParameters.clear();
	}

	virtual void setState(state newState)
	{
		this->CurrentState = availableStates[newState];
		this->stateIndex = newState;
	}

	virtual int getStateIndex(void)
	{
		return this->stateIndex;
	}

	virtual void setStateParam(stateParameter SP, int value)
	{
		this->stateParameters[SP] = value;
	}
	virtual int getStateParam(stateParameter SP)
	{
		return this->stateParameters[SP];
	}
};

class Transition
{
public:
	virtual bool addResource(int) { cout << "Error!" << endl; return false; }
	virtual bool makeSelection(int) { cout << "Error!" << endl; return false; }
	virtual bool returnResource(void) { cout << "Error!" << endl; return false; }
	virtual bool addNPCs(int) { cout << "Error!" << endl; return false; }
	virtual bool spawn(void) { cout << "Error!" << endl; return false; }
};

class NPCState : public State, public Transition
{
public:
	NPCState(StateContext* Context) : State(Context) {}
};

class NoNPCs : public NPCState
{
public:
	NoNPCs(StateContext* Context) : NPCState(Context)
	{
	}
	bool addResource(int resource)
	{
		//===============================
		cout << "Error ! No Resourse ! no Selection made " << endl;
		return false;
	}
	bool makeSelection(int option)
	{
		cout << "Error ! No Selections left ! no Selection made " << endl;
		return false;
	}
	bool returnResource(void)
	{
		cout << " Resouce Rejected ! " << endl;
		this->CurrentContext->setStateParam(RESOURCES, 0);
		this->CurrentContext->setState(NO_NPCS);
		return true;
	}
	bool addNPCs(int number)
	{
		this->CurrentContext->setStateParam(NPCS, number);
		this->CurrentContext->setState(NO_RESOURCES);
		return true;
	}
	bool spawn(void)
	{
		cout << "Error ! No Spawn left ! no thing to dispense " << endl;
		return false;
	}
};

class NoResources : public NPCState
{
public:
	NoResources(StateContext* Context) : NPCState(Context) 
	{
	}
	bool addResource(int resource)
	{
		cout << "Your  Resource  ! " << endl;
		this->CurrentContext->setStateParam(RESOURCES, resource);
		cout << "TOTAL Resource  : " << resource << endl;
		this->CurrentContext->setState(HAVE_RESOURCES);
		return true;
	}
	bool makeSelection(int option)
	{
		cout << "Error ! No Resource  " << endl;
		return false;
	}
	bool returnResource(void)
	{
		cout << "Error ! Resource Rejected  " << endl;
		return false;
	}
	bool addNPCs(int number)
	{
		cout << "Error ! Already Got Resource " << endl;
		return false;
	}
	bool spawn(void)
	{
		cout << "Error !No Resource  " << endl;
		return false;
	}
};

class HaveResources : public NPCState
{
public:
	HaveResources(StateContext* Context) : NPCState(Context)
	{
	}
	bool addResource(int resource)
	{
		cout << "You choosed  ! " << resource << endl;
		resource = resource + this->CurrentContext->getStateParam(RESOURCES);
		this->CurrentContext->setStateParam(RESOURCES, resource);
		cout << "TOTAL : " << resource << endl;
		this->CurrentContext->setState(HAVE_RESOURCES);
		return true;
	}
	bool makeSelection(int option);
	bool returnResource(void)
	{
		cout << "Error ! Resource Rejected  " << endl;
		this->CurrentContext->setStateParam(RESOURCES, 0);
		this->CurrentContext->setState(NO_RESOURCES);
		return true;
	}
	bool addNPCs(int number)
	{
		cout << "Error ! Already Got Resource " << endl;
		return false;
	}
	bool spawn(void)
	{
		cout << "Error ! No Resource  " << endl;
		return false;
	}
};

class SpawnNPC : public NPCState
{
public:
	SpawnNPC(StateContext* Context) : NPCState(Context)
	{
	}
	bool addResource(int resource)
	{
		cout << "busy  Dispensing  " << endl;
		return false;
	}
	bool makeSelection(int option)
	{
		cout << "Error ! busy Dispensing" << endl;
		return false;
	}

	bool returnResource(void)
	{
		cout << "Error ! busy Dispensing " << endl;
		return false;
	}
	bool addNPCs(int number)
	{
		cout << "Error ! busy Dispensing  " << endl;
		return false;
	}
	bool spawn(void);
};


class Weapon;

class NPC
{
protected:
	string _description = "NPC";
	int _cost = 0;
	int _damage = 0;
public:
	string description(void) { return this->_description; };
	int cost(void) { return this->_cost; }
	int damage(void) { return this->_damage; }
	virtual int bestDamage(int best_weapon_damage = 0) { return 0; } //returns the best damage an NPC can do - i.e. base damage + highest damage weapon. Should return 0 if not implemented
	virtual int costAll(void) { return this->cost(); } //returns NPC base cost
	virtual string describeAll(void) { return this->description(); } //returns description of NPC
	virtual Weapon* ReturnHighestCostWeapon(void) { return nullptr; } //returns nullptr
};
        
class Peon : public NPC
{
public:
	string _description = "Peon ";
	int _cost = 100;
	int _damage = 10;
};

class Grunt : public NPC
{
public:
	string _description = "Grunt ";
	int _cost = 150;
	int _damage = 20;
};

class Raider : public NPC
{
public:
	string _description = "Raider ";
	int _cost = 200;
	int _damage = 30;
};

class Tauren : public NPC
{
public:
	string _description = "Tauren ";
	int _cost = 250;
	int _damage = 40;
};

class Shaman : public NPC
{
public:
	string _description = "Shaman ";
	int _cost = 300;
	int _damage = 50;
};


class Weapon : public NPC
{
protected:
	NPC* FilledNPC = nullptr;
public:
	~Weapon(void)
	{
	}
	void equipNPC(NPC* NewNPC)
	{
	}
	int costAll(void) //returns cost of NPC + all weapons
	{
		return 0;
	}
	int bestDamage(int best_weapon_damage = 0) //returns the best damage an NPC can do - i.e. base damage + highest damage weapon
	{
		return this->bestDamage() + this->damage();
	}
	string describeAll(void) //returns string description of NPC + all weapons
	{
		return this->description();
	}
	Weapon* ReturnHighestCostWeapon(void) //returns a pointer to the high cost weapon. Should return nullptr if not implemented
	{
		return nullptr;
	}
};
	class NPCGenerator : public StateContext, public Transition
	{
		friend class SpawnNPC;
		friend class HaveResources;
	private:
		NPCState* NPCCurrentState = nullptr;
		bool itemDispensed = false; //indicates whether a NPC is there to be retrieved - needed for ownership managemnt
		NPC* SpawnedNPC = nullptr; //
		bool itemRetrieved = false; //indicates whether a NPC has been retrieved - needed for ownership managemnt
	public:
		NPCGenerator(int inventory_count);
		~NPCGenerator(void);
		bool addResource(int resource);
		bool makeSelection(int option);
		bool returnResource(void);
		bool addNPCs(int number);
		bool spawn(void);
		NPC* getNPC(void);
		virtual void setStateParam(stateParameter SP, int value);
		virtual int getStateParam(stateParameter SP);
	};

	NPCGenerator::NPCGenerator(int inventory_count)
	{
		this->availableStates.push_back(new NoNPCs(this));
		this->availableStates.push_back(new NoResources(this));
		this->availableStates.push_back(new HaveResources(this));
		this->availableStates.push_back(new SpawnNPC(this));
		this->stateParameters.push_back(0);// no of Chocolate
		this->stateParameters.push_back(0);// available credit

		this->setState(NO_NPCS);
		if (inventory_count > 0)
		{
			this->addNPCs(inventory_count);
		}
	}

	NPCGenerator::~NPCGenerator(void)
	{
		if (!this->itemRetrieved)
		{
			delete this->SpawnedNPC;
		}
	}

	bool NPCGenerator::addResource(int resource)
	{
		NPCCurrentState = (NPCState*)this->CurrentState;
		return this->NPCCurrentState->addResource(resource);
	}

	bool NPCGenerator::makeSelection(int option)
	{
		NPCCurrentState = (NPCState*)this->CurrentState;
		return this->NPCCurrentState->makeSelection(option);
	}

	bool NPCGenerator::returnResource(void)
	{
		NPCCurrentState = (NPCState*)this->CurrentState;
		return this->NPCCurrentState->returnResource();
	}

	bool NPCGenerator::addNPCs(int number)
	{
		NPCCurrentState = (NPCState*)this->CurrentState;
		return this->NPCCurrentState->addNPCs(number);
	}

	bool NPCGenerator::spawn(void)
	{
		NPCCurrentState = (NPCState*)this->CurrentState;
		return this->NPCCurrentState->spawn();
	}

	NPC* NPCGenerator::getNPC(void)
	{
		//handles transfer of NPC object ownership
		if (this->itemDispensed)
		{
			this->itemDispensed = false;
			this->itemRetrieved = true;
			return this->SpawnedNPC;
		}

		return nullptr;
	}

	void NPCGenerator::setStateParam(stateParameter SP, int value)
	{
		this->stateParameters[SP] = value;
	}

	int NPCGenerator::getStateParam(stateParameter SP)
	{
		return this->stateParameters[SP];
	}

	bool HaveResources:: makeSelection(int option)
	{
		cout << "Selectin made  " << endl;// specific selection not made yet
		if (!((NPCGenerator*)this->CurrentContext)->itemRetrieved)
		{
			delete ((NPCGenerator*)this->CurrentContext)->SpawnedNPC;
			// delete product if one was created , but not retrived
		}
		((NPCGenerator*)this->CurrentContext)->SpawnedNPC = new Weapon;
		((NPCGenerator*)this->CurrentContext)->itemRetrieved = false;
		//need to factor in pricing here
		this->CurrentContext->setState(SPAWN_NPC);
		return true;
	}

	bool SpawnNPC:: spawn(void)
	{
		if (this->CurrentContext->getStateParam(RESOURCES) >= ((NPCGenerator*)this->CurrentContext)->SpawnedNPC->cost())
		{
			cout << "Dispensing ! " << endl;
			this->CurrentContext->setStateParam(RESOURCES, this->CurrentContext->getStateParam(RESOURCES)-((NPCGenerator*)this->CurrentContext)->SpawnedNPC->cost());
			this->CurrentContext->setStateParam(NPCS, this->CurrentContext->getStateParam(NPCS)- 1);
			((NPCGenerator*)this->CurrentContext)->itemDispensed = true;
		}
		else
		{
			cout << "Error ! no enough Resource  " << endl;
		}

		if (this->CurrentContext->getStateParam(RESOURCES) > 0)
		{
			this->CurrentContext->setState(HAVE_RESOURCES);
		}
		else
		{
			this->CurrentContext->setState(NO_RESOURCES);
		}

		if (this->CurrentContext->getStateParam(NPCS) == 0)
		{
			this->CurrentContext->setState(NO_NPCS);
		}
		else
		{
			this->CurrentContext->setState(NO_RESOURCES);
		}
		return true;
	}

	
