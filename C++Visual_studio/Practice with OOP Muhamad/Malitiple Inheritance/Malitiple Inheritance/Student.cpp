#include "Student.h"
using namespace std;
#include<iostream>

void Student::setName(string n)
{
	name = n;
}

string Student::getName()
{
	return name;
}

void Student::setDepartment(string d)
{
	department = d;
}

string Student::getDepartment()
{
	return department;
}

void Student::setResearch_interast(string r)
{
	research_interast = r;
}

string Student::getResearch_interast()
{
	return research_interast;
}

void Student::display()
{
	cout << "name  " << "   " << name << endl;
	cout << "deparetment  " << "   " << department << endl;
	cout << "research interast  " << "   " << research_interast << endl;
}

Student::Student()
{
}

Student::Student(string n, string d, string r):name(n),department(d),research_interast(r)
{
}

Student::~Student()
{
}
