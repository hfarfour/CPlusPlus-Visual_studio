#include "person.h"
using namespace std;
#include<string>
#include <iostream>


void person::setname(string n)
{
	name = n;
}

string person::getName()
{
	return name;
}

void person::setGender(string g)
{
	gender = g;
}

string person::getGender()
{
	return gender;
}

void person::setAge(float a)
{
	age = a;
}

float person::getAge()
{
	return age;
}

person::person() :name("hossam"), gender("male"), age(29)
{
}

person::person(string n, string g, float a) :name(n), gender(g),age(a)
{

}

person::~person()
{
	cout << "good bay " << endl;
}
