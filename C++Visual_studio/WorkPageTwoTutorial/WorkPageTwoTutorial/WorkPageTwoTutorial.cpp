// WorkPageTwoTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<vector>
#include <iostream>
using namespace std;

class Beverage
{
public:
    virtual void display() {}
    virtual void prepare() {}
};

class Tea : public Beverage
{
    void display()
    {
        cout << "TEA" << endl;
    }
    void prepare()
    {
        cout << "adding tea bag......Brewing...adding milk...adding suger,," << endl;
    }
};
class coffee :public Beverage
{
    void dispaly()
    {
        cout << "COFFEE" << endl;
    }
    void prepare()
    {
        cout << "Grinding Beans...percolating...Adding milk...Adding suger" << endl;
    }

};
class fruitJuice : public Beverage
{
    void display()
    {
        cout << "fruit juice " << endl;
    }
    void prepare()
    {
        cout << "squeezing fruit and pouring juice  " << endl;
    }

};
class vendingMachine
{
    vector <Beverage*> Drings;
public:
    vendingMachine()
    {
        // consstructor drink vector
        Drings.push_back(new Tea());
        Drings.push_back(new coffee());
        Drings.push_back(new fruitJuice());
    }
    ~vendingMachine()
    {
       // delete drink objects
        for (int dringCount = 0; dringCount < Drings.size(); dringCount++)
        {
            delete Drings[dringCount];
        }
    }
    void displayBeverages()
    {
        int count = 1;
        for (int count = 1; count <= Drings.size(); count++)
        {
            cout << count <<  ")";
            Drings[count-1]-> display();
        }
    }
    void selectBeverage()
    {
        int choice;
        this->displayBeverages();

        cout << "Enter choice " << endl;
        cin >> choice;
        if (choice > Drings.size() || choice < 1)
            cout << "bad choice " << endl;
        else
            Drings[choice -1]-> prepare();
    }   
};

int main()
{
    std::cout << "Hello World!\n";
}
