// Observer Battern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Observer
{
protected:
    Subject* pMySubject = nullptr;
public:
    virtual void setSubject(Subject* pCurrentSubject)
    {
        this->pMySubject = pCurrentSubject;
    }
    virtual void removeSubject()
    {
        pMySubject->removeObserver(this);
        pMySubject = nullptr;
    }
    virtual void update()
    {

    }

};


class Subject
{
protected:
    vector<Observer*> MyObserver;
    virtual bool observerExists(Observer* pObserver)
    {
        if (pObserver == nullptr) return false;
        for (int observercount = 0; observercount < MyObserver.size(); observercount++)
        {
            if (MyObserver[observercount] == pObserver)
            {
                return true;
            }
        }
        return false;
    }
public:
    ~Subject()
    {
        MyObserver.clear();
    }
    virtual void registerObserver(Observer* pNewObserver)
    {
        pNewObserver->setSubject(this);
        MyObserver.push_back(pNewObserver);
    }
    virtual void removeObserver(Observer* pObserverToRemove)
    {
        for (int observercount = 0; observercount < MyObserver.size(); observercount++)
        {
            if (MyObserver[observercount] == pObserverToRemove)
            {
                MyObserver.erase(MyObserver.begin() + observercount);
                return;
            }
        }
    }
    virtual void notifyObserver()
    {
        for (int observercount = 0; observercount < MyObserver.size(); observercount++)
        {
            MyObserver[observercount]->update();
        }
    }
};



class WeatherStation : public Subject
{
private:
    float humidity = 0, temperature = 0, pressure = 0;
public:
    void setWeatherValues(float newHumidity, float newtemperature, float newPressure)
    {
        humidity = newHumidity;
        temperature = newtemperature;
        pressure = newPressure;
    }
    float getHumidity()
    {
        return humidity;
    }
    float getTemperature()
    {
        return temperature;
    }
    float getPressure()
    {
        return pressure;
    }
};

class WeatherClient : public Observer
{
    void update()
    {
        WeatherStation* WeatherData = (WeatherStation*)pMySubject;
        cout << "Humidity = " << WeatherData->getHumidity() << " : Tempreture = : " << WeatherData->getTemperature() << " pressure = :" << WeatherData->getPressure() << endl;
    }
};

class NPCcontroller : public Subject
{
    vector<string> npcgroupcommands = { "STAY","MOVE","ATTACK","DEFEND" };
};


class NPC : public Observer
{
private:
    string lastcommand = "";
    NPCBehaviour* CurrentBehaviour = nullptr;
public:
    NPC()
    {
        this->CurrentBehaviour = new DefaultNPCBehaviour;
    }
    void setBehaviour(NPCBehaviour* NewBehaviour)
    {
        delete this->CurrentBehaviour;
        this->CurrentBehaviour = NewBehaviour;
    }

    int groupnumber = 0;
    void act()
    {
        if (CurrentBehaviour != nullptr)
            this->CurrentBehaviour->act(this->lastcommand);
    }
    string getCommand()
    {
        return lastcommand;
    }
    void update()
    {
        NPCcontroller* controller = (NPCcontroller*)pMySubject;
        lastcommand = controller-> npcgroupcommands[groupnumber];
    }

};

class NPCBehaviour
{
public:
    virtual void act(string command)
    {

    }

};

class DefaultNPCBehaviour :public NPCBehaviour
{

public:
    virtual void act(string command)
    {
        cout << command << endl;
    }

};

class AggressiveNPCBehaviour :public NPCBehaviour
{

public:
    virtual void act(string command)
    {
        if (command == "DEFEND")
            cout << "ATTACK " << endl;
        else

        cout << command << endl;
    }

};

class DefensiveNPCBehaviour :public NPCBehaviour
{

public:
    virtual void act(string command)
    {
        if (command == "ATTACK")
            cout << "DEFEND " << endl;
        else

            cout << command << endl;
    }

};




int main()
{

    NPCcontroller GameController;
    vector<NPC> NPCs;

    //initialise NPCs
    for (int count = 0; count < NUMBEROFNPCs; count++)
    {
        NPCs.push_back(new NPC);
        NPCs[count]->groupnumber = count;
        GameController.registerObserver(NPCs[count]);

    }
    //stimulate NPC command sequence
    for (int stepcount = 0; stepcount < 3; stepcount++)
    {
        switch (stepcount)
        {
        case 0:
            break;

        case 1:
            GameController.npcgroupcommand[2] = "DEFEND";
            cout<<"Group 2 was issued a 'DEfend' command" <<endl<<endl;
            break;

        case 2:
            NPCs[2]->groupnumber = 0;
            cout << "NPC 3 was moved to group 0 " << endl << endl;
            break;

        default:
            break;
        }
        GameController.notifyObserver();
        for (int count = 0; count < NPCs.size(); count++)
        {
            cout << "last command to NPC " << count + 1 << "in geoup " << NPCs[count]->groupnumber << "was " << NPCs[count]->getCommand() << endl;
        }
    }

    cout << endl << "the last command sent to NPC 4 was " << NPCs[3]->getCommand() << endl;
    cout << "changing default behaviour to Aggresive " << endl;
    NPCs[3]->setBehaviour(new AggressiveNPCBehaviour);
    cout << "Commanding the NPC to act  " << endl;
    NPCs[3]->act();
    //Deallocate resources
    for (int count = 0; count < NPCs.size(); count++)
    {
        delete NPCs[count];
    }
    return 0;

    //Obersver pattern implementation
   /* WeatherStation* NewWeatherStation = new WeatherStation;
    WeatherClient* NewWeatherClient = new WeatherClient;

    NewWeatherStation->registerObserver(NewWeatherClient);
    NewWeatherStation->notifyObserver();
    NewWeatherStation->setWeatherValues(20, 20, 20);
    NewWeatherStation->notifyObserver();

    NewWeatherClient->removeSubject();

    NewWeatherStation->notifyObserver();

    delete NewWeatherClient;
    delete NewWeatherStation;
    return 0;*/

}
