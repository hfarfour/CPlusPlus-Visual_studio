// Composition.cpp : va inheritance 
#include <iostream>
using namespace std ;

// inheritance

class Duck
{
public:
    void fly()
    {
        cout << "flap" << endl;
    }
    void quack()
    {
        cout << "Quacking" << endl;
    }
    void waddle()
    {
        cout << "waddeling" << endl;
    }

};
class Mallard : public Duck  // by inheritance //  is a Duck
{
public:
    
};

//=====================================================
// composition

class Dunclair  // by composition // has a  Duck
{
private:
    Duck myInnerDuck; //owned
public:
    void quack()
    {
        myInnerDuck.quack();
    }
    void fly()
    {
        myInnerDuck.fly();    // shoud typed minually
    }
    void waddle()
    {
        myInnerDuck.waddle();
    }

};

int main()
{
    Mallard myFirstDuck;
    Dunclair mySecondDuck;

    myFirstDuck.quack();
    mySecondDuck.quack();
    
}