
#include <iostream>
using namespace std;
#include "car.h"
#include"vehicle.h"


int main()
{
	car c1("honda", 2020, "black");
	cout << "the car is made by " << c1.getMaker() << endl;     // i used here constracter instead
	cout << " this  car model is " << c1.getModel() << endl;  // i used here constracter instead
	cout << " this  car model is " << c1.getColor() << endl;
	cout << "================================================" << endl;
	car c2("BMW", 2021, "yellow");
	cout << "the car is made by " << c2.getMaker() << endl;    // intializition list
	cout << " this  car model is " << c2.getModel() << endl;  
	cout << " this  car model is " << c2.getColor() << endl;


  // cout << "the car is made by" << c1.getMaker() << endl;
  // cout << " this  car model is " << c1.getModel() << endl;      // for instractor
 //  cout << " this  car color is " << c1.getColor() << endl;
	cout << "================================================" << endl;
	


	//constrctor OverLoading
	car c3;
	cout << "the car is made by " << c3.getMaker() << endl;     
	cout << " this  car model is " << c3.getModel() << endl;  
	cout << " this  car model is " << c3.getColor() << endl;
	cout<< "================================================" << endl;

	vehicle f1;
		cout << f1.getMaker() << endl;


	//vehicle f1("lambr",2029,"red")
	//cout << f1.getMaker()<< endl;

}
