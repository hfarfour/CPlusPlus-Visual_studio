// Strategy Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Composition.cpp : va inheritance and strategy pattern 
#include <iostream>
using namespace std;

// strategy pattern
class FlyBehaviour
{
public:
    virtual void fly()
    {
        cout << "I fly " << endl;
    }
};

class QuackBehaviour
{
public:
    virtual void quack()
    {
        cout << "I quack " << endl;
    }
};

class FlyWithwings : public FlyBehaviour
{
    void fly()
    {
        cout << "flap flap " << endl;
    }

};

class NormalQuack : public QuackBehaviour
{
   void quack()
    {
        cout << "quack quack" << endl;
    }
};


class FlyNoWay : public FlyBehaviour
{
    void fly()
    {
        cout << "I do not fly " << endl;
    }
};

class Squeak:QuackBehaviour
{
    void quack()
    {
        cout << "squeak squeak " << endl;
    }
};

// here is the change 
class Duck
{
private:
    FlyBehaviour* pCurrentFlyBehaviour = nullptr;
    QuackBehaviour* pCurrentQuackBehaviour = nullptr;
public:
    Duck()
    {
        pCurrentFlyBehaviour = new FlyWithwings;
        pCurrentQuackBehaviour = new NormalQuack;
    }
    virtual ~Duck()
    {
        delete pCurrentFlyBehaviour;
        delete pCurrentQuackBehaviour;
    }
    virtual void quack()
    {
        if (pCurrentQuackBehaviour != nullptr)
            pCurrentQuackBehaviour->quack();
    }
    void swim()
    {
        cout << "swim swim " << endl;
    }
    virtual void display()
    {
        cout << "I am a Duck..." << endl;
    }
    virtual void fly()
    {
        if (pCurrentFlyBehaviour != nullptr)
            pCurrentFlyBehaviour->fly();
    }
    void setFlyBehaviour(FlyBehaviour* pMyFlyBehaviour)
    {
        delete pCurrentFlyBehaviour;
        pCurrentFlyBehaviour = pMyFlyBehaviour;
    }
    void setQuackBehaviour(QuackBehaviour* PNewQuackBehaviour)
    {
        delete pCurrentQuackBehaviour;
        pCurrentQuackBehaviour = PNewQuackBehaviour;
    }

};

class MallardDuck : public Duck  // by inheritance //  is a Duck
{
public:
    MallardDuck()
    {
        setFlyBehaviour(new FlyWithwings);
        setQuackBehaviour(new NormalQuack);   
    }
    void display()
    {
        cout << "I am a mallard Duck..........." << endl;
    }
};


class RedHeadDuck :public Duck
{
public:
    RedHeadDuck()
    {
        setFlyBehaviour(new FlyWithwings);
        setQuackBehaviour(new NormalQuack);
    }
    void display()
    {
        cout << "I am a redhead Duck......." << endl;
    }
};

int main()
{
    MallardDuck myMallardDuck;
    myMallardDuck.display();
    myMallardDuck.fly();
    myMallardDuck.setFlyBehaviour(new FlyNoWay);
    myMallardDuck.fly();
    return 0;
}