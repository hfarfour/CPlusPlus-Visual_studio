#pragma once
#include<string>
#include"person.h"
using namespace std;

class person
{
private:
	string name;
	string gender;
	float age;
public:
	void setname(string n);
	string getName();
	void setGender(string g);
	string getGender();
	void setAge(float a);
	float getAge();
	person();
	person(string n, string g, float a);
	~person();


};

