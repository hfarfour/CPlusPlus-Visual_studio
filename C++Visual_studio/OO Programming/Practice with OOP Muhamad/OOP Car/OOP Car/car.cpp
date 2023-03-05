#include "car.h"
#include <iostream>
using namespace std;



void car::setMaker(string m)
{
	maker = m;
}

string car::getMaker()
{
	return maker;
}

void car::setModel(int mo)
{
	model = mo;
}

int car::getModel()
{
	return model;
}

void car::setColor(string co)
{
	color = co;
}
string car::getColor()
{
	return color;
}



// for overLoading constractor;
car::car() : maker("Tyota") , model(3013) , color("blue")
{

}

car::car(string m, int mo, string co) : maker(m), model ( mo), color (co)
{	//maker = "honad";
	//model = 2018;
	//color = "white";
}

car::~car()
{
	cout << "good bay" << endl;
}
