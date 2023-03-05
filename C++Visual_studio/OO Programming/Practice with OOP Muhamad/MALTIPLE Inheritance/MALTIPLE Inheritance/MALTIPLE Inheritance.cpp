#include <iostream>
#pragma once
#include<string>
using namespace std;


class Employee
{
private:
	string name;
	string job;
	float salary;
public:
	void setName(string N)
	{
		name = N;
	}
	/*string getName()
	{
		return name;
	}*/

	void setJob(string j)
	{ 
		job = j;
	}

	string getJob()
	{
		return job;
	}
	void setSalary(float s)
	{
		salary = s;
	}
	float getSalary()
	{
		return salary;
	}
	void display()
	{
		cout << "name  " << "   " << name << endl;
		cout << "jod  " << "   " << job << endl;
		cout << "salary  " << "   " << salary << endl;
	}

	Employee()
	{
		name = "hossam";
		job = "ertired";
		salary = 143.23;
	}
	Employee(string N, string j, float s)
	{
		name=N;
		job=j;
		salary = s;
	}

	~Employee()
	{
	}

};


class Student
{
private:
	string name;
	string department;
	string research_interast;
public:
   void setName(string n)
	{
		name = n;
	}

	/*string getName()
	{
		return name;
	}*/
	void setDepartment(string d)
	{
		department = d;
	}
	string getDepartment()
	{
		return department;
	}
	void setResearch_interast(string r)
	{
		research_interast = r;
	}
	string getResearch_interast()
	{
		return research_interast;
	}

	void display()
	{
          
		cout << "deparetment  " << "   " << department << endl;
		cout << "research interast  " << "   " << research_interast << endl;
	}

	Student()
	{
		department = "USW";
		research_interast = "science";

	}
	Student( string d, string r)
	{
		department = d;
		research_interast = r;
	}
	~Student()
	{
	}
};

class teachingAssistant : public Student, public Employee
{
public:
	void disblay()
	{
		Employee::display();
		Student::display();
	}
	teachingAssistant( string N, string j, float s, string d, string r) : Employee(N, j, s), Student(d, r)
	{
	}
	~teachingAssistant()
	{
	}

};


int main()
{
	teachingAssistant t1("hamad", "retired", 123.43, "SUOUTH", "Computer");
		t1.setSalary(300);
		t1.setDepartment("wales batatbase");	
		t1.Employee::setName("ali");          // very important
		t1.Student::setName("sam");

	    t1.disblay();

   
}


