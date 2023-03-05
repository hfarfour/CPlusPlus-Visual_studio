#include "Student.h"

void Student::setLevel(int le)
{
	level = le;
}

int Student::getlevel()
{
	return level;
}

void Student::setGPA(float gp)
{
	GPA = gp;
}

float Student::getGPA()
{
	return GPA;
}

void Student::setDepart(string de)
{
	depart = de;
}

string Student::getDepart()
{
	return depart;
}



Student::Student():level(35),GPA(10.9),depart("high")
{
}

Student::Student(string n, string g, float a, int le, float gp, string de):person(n,g,a)
{
	level = le;
	GPA = gp;
	depart = de;
}


Student::~Student()
{
}
