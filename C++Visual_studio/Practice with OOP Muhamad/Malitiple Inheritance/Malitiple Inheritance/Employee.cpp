#include "Employee.h"
using namespace std;
#include<iostream>

void Employee::setName(string n)
{
	name = n;
}

string Employee::getName()
{
	return name;
}

void Employee::setJob(string j)
{
	job = j;
}

string Employee::getJob()
{
	return job;
}

void Employee::setSalary(float s)
{
	salary = s;
}

float Employee::getSalary()
{
	return salary;
}

void Employee::display()
{
	cout << "name  " << "   " << name << endl;
	cout << "jod  " << "   " << job<< endl;
	cout << "salary  " << "   " << salary << endl;



}

Employee::Employee()
{
}

Employee::Employee(string n, string j, float s):name(n),job(j),salary(s)
{
}

Employee::~Employee()
{
}
