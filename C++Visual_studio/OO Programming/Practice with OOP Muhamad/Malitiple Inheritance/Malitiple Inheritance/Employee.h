#pragma once
#include"Employee.h"
#include<string>
using namespace std;
class Employee
{
private:
	string name;
	string job;
	float salary;
public:
	void setName(string n);
	string getName();
	void setJob(string j);
	string getJob();
	void setSalary(float s);
	float getSalary();
	void display();

	Employee();
	Employee(string n, string j, float s);
	~Employee();

};

