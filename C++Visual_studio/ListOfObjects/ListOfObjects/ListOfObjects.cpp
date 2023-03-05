
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



class person
{
public:
    int age;
    string name;
    person() : age(0) {}     //defult constractor
    person(int age, string name)
    {
        this->age = age;
        this->name = name;
    }
    bool operator<(const person& rhs)
    {
        return this->age < rhs.age;
    }

    // i use this code for oreventing to print same age //unique pointer//

    bool operator==(const person& rhs)const
    {
        if (this->age != rhs.age)
            return false;
        else
            return true;
    }

};



int main()
{
    list<person>listperson;
    listperson.push_back(person(24, "sam"));
    listperson.push_back(person(30, "ali"));
    listperson.push_back(person(30, "hamed"));
    listperson.push_back(person(28, "issa"));

    listperson.sort();
    list<person>::iterator it;
    listperson.unique();

    cout << "my list content : " << endl;
    for (it = listperson.begin(); it != listperson.end(); ++it)
        cout << it->age << " , " << it->name << endl;
    system("pause");
    return 0;
}
