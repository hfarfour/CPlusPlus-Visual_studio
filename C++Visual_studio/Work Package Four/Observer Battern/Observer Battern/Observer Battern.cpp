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
                return true ;
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

int main()
{
    //Obersver pattern implementation
    WeatherStation* NewWeatherStation = new WeatherStation;
    WeatherClient* NewWeatherClient = new WeatherClient;

    NewWeatherStation->registerObserver(NewWeatherClient);
    NewWeatherStation->notifyObserver();
    NewWeatherStation->setWeatherValues(20,20,20);
    NewWeatherStation->notifyObserver();

    NewWeatherClient->removeSubject();

    NewWeatherStation->notifyObserver();

    delete NewWeatherClient;
    delete NewWeatherStation;
    return 0;

}
