// DecoratingObjects.cpp : This file contains the 'main' function. Program execution begins and ends there.






//key feature of a Decorator object. it inherits an interface but also has aa composition relationship to the same interface
// this is recursion
//recursion is the heart of Decorator pattern
#include <iostream>
#include <string>
using namespace std;


class Beverage
{
protected:
    string itemName = "";
    float itemCost = 0;
    string brewDetails = "";
    string boilWaterDetails = "";
public:
    virtual string name()
    {
        return this->itemName;
    }
    virtual float cost()
    {
        return this->itemCost;
    }
    virtual ~Beverage()
    {

    }

    virtual void brew()
    {
        cout << brewDetails << endl;
    }
    virtual void boilwater()
    {
        cout << boilWaterDetails << endl;
    }
    virtual void pour()
    {
        cout << "pour " << endl;
    }
    virtual void displayOrder()
    {
        cout << this->name() << " : Cost : ";
        cout << this->cost() <<endl;
    }
    virtual void prepare()
    {
        boilwater();
        brew();
        pour();
    }

};

class Espresso : public Beverage
{
public:
    Espresso()
    {
        itemName = "Espresso ";
        itemCost = 1.2;
        brewDetails = "filtering espresso ";
        boilWaterDetails = " Heating to 90 celsius";

    }

};


class Tea : public Beverage
{
public:
    Tea()
    {
        itemName = "Tea ";
        itemCost = 1.2;
        brewDetails = "Steeping teabag ";
        boilWaterDetails = " Heating to 100 celsius";

    }

};


class GreanTea : public Beverage
{
public:
    GreanTea()
    {
        itemName = "GreanTea ";
        itemCost = 1.0;
        brewDetails = "Steeping teabag ";
        boilWaterDetails = " Heating to 120 celsius";

    }

};

//key feature of a Decorator object. it inherits an interface but also has aa composition relationship to the same interface
class CondimentDecorator : public Beverage
{
protected:
    Beverage* beverage;
    string addcondimentdetails = "";
public:
    virtual float cost()
    {
        return this->itemCost + beverage->cost();
    }
    virtual string name()
    {
        return beverage->name() + " + " + this->itemName;
    }
    virtual void addCondiment()
    {
        cout << addcondimentdetails << endl;
    }

    void addToBeverage(Beverage* customerBeverage)
    {
       beverage= customerBeverage;
    }

    ~CondimentDecorator()
    {
        delete beverage;
    }
     void prepare()
    {
         beverage->prepare();
         addCondiment();//adding a condiment makes sense here
    }

     virtual void brew()
     {
         beverage->brew();
     }

     virtual void boilWater()
     {
         beverage->boilwater();
     }
     void pour()
     {
         beverage->pour();
     }

};

class Mocha : public CondimentDecorator
{
public:
    Mocha()
    {
        itemName = "Mocha";
        itemCost = 0.2;
        addcondimentdetails = "Adding Mocha";
    }
};

class Cream : public CondimentDecorator
{
public:
    Cream()
    {
        itemName = "Cream";
        itemCost = 0.5;
        addcondimentdetails = "Adding Cream";
    }
};
class Suger: public CondimentDecorator
{
public:
    Suger()
    {
        itemName = "Suger";
        itemCost = 0.8;
        addcondimentdetails = "Adding Suger";
    }
};


class Syrup : public CondimentDecorator
{
public:
    Syrup()
    {
        itemName = "Syrup";
        itemCost = 0.2;
        addcondimentdetails = "Adding Syrup";
    }
};




int main()
{
    Beverage* currentBeverage = new Tea;
    currentBeverage->displayOrder();
    cout << "================" << endl;
    CondimentDecorator* currentCondiment = new Mocha;
    currentCondiment->addToBeverage(currentBeverage);
    currentBeverage = currentCondiment;
    currentBeverage->displayOrder();
    cout <<"================"<< endl;
    currentCondiment = new Cream;
    currentCondiment->addToBeverage(currentBeverage);
    currentBeverage = currentCondiment;
    currentBeverage->displayOrder();
    cout << "================" << endl;

    currentCondiment = new Suger;
    currentCondiment->addToBeverage(currentBeverage);
    currentBeverage = currentCondiment;
    currentBeverage->displayOrder();

    cout << "================" << endl;

    cout << "================" << endl;

    currentCondiment = new Syrup;
    currentCondiment->addToBeverage(currentBeverage);
    currentBeverage = currentCondiment;
    currentBeverage->displayOrder();

    cout << "================" << endl;

    currentBeverage->prepare();
    delete currentBeverage;
    return 0;

   /* Beverage* currentBeverage = new Tea;
    CondimentDecorator* currentCondiment = nullptr;
    for (int stepcount = 0; stepcount < 3; stepcount++)
    {
        switch (stepcount)
        {
        case 0:
            currentCondiment = new Suger;
            break;
        case 1:
            currentCondiment = new Mocha;
            break;
        case 2:
            currentCondiment = new Cream;
            break;

        default:
            break;
        }
        if (currentCondiment != nullptr)
        {
            currentCondiment->addToBeverage(currentBeverage);
            currentBeverage = currentCondiment;
        }
        else
        {
            currentCondiment = nullptr;
        }
        currentBeverage->displayOrder();
    }
    currentBeverage->prepare();
    delete currentBeverage;
    return 0;*/

}
