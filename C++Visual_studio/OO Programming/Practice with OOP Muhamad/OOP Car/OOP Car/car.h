#pragma once
#include<string>
using namespace std;


class car
{
private:
	string maker;
	int model;
	string color;
	
public:
	void setMaker(string m);
	string getMaker();
	void setModel(int mo);
	int getModel();
	void setColor(string co);
	string getColor();
	


	// constractor 
	//car(string m,int mo,string co);
	//~car();

	// constractor overloading
	car();
	car(string m, int mo, string co);
	~car();

};

