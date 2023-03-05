#pragma once
#include"person.h"
#include"Student.h"
#include<iostream>
using namespace std;
class Student : public person

{
private:

	int level;
	float GPA;
	string depart;
public:
	void setLevel(int le);
	int getlevel();
	void setGPA(float gp);
	float getGPA();
	void setDepart(string de);
	string getDepart();

	Student();
	Student(string n, string g, float a, int le,float gp,string de );
	~Student();
};

