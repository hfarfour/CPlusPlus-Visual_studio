#include<string>
#include<iostream>
#include"person.h"
#include"Student.h"
using namespace std;



int main()
{
	person p1("ali", "female", 30);
	person p2;
	cout << p1.getName() << endl;
	cout << p2.getName() << endl;
	cout << p1.getGender() << endl;
	cout << p2.getGender() << endl;
	cout << "==========================" << endl;

	Student s1;
	cout << s1.getName() << endl;
	cout << s1.getGender() << endl;    // calling outomatically base calss constractor
	//s1.setDepart("comuter");
	//s1.setLevel(12);
	//s1.setGPA(15.55);
	cout << "==========================" << endl;
	Student s2("hamd","male",38,45,45.5,"sceince");
	cout<<s2.getName() << endl;
	cout << s2.getDepart() << endl;
	cout << s2.getGender() << endl;
	cout << s2.getlevel() << endl;
	cout << s2.getGPA() << endl;
	
	cout << "==========================" << endl;
	Student s3;
	cout << s3.getDepart() << endl;




}
