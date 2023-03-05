#pragma once

#include"Student.h"
#include<string>
using namespace std;



class Student
{
	private:
		string name;
		string department;
		string research_interast;
	public:
		void setName(string n);
		string getName();
		void setDepartment(string d);
		string getDepartment();
		void setResearch_interast(string r);
		string getResearch_interast();
		void display();

		Student();
		Student(string n, string d, string r );
		~Student();

	


};

