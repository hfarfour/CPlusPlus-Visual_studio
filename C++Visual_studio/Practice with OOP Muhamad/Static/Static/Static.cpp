#include<iostream>
#include <iostream>
using namespace std;
#include"Calculator.h"
int main()
{
	cout << Calculator::add(2, 5) << endl;
	cout << Calculator::multiply(5, 5) << endl;
	cout << Calculator::subtract(10, 5) << endl;
}
