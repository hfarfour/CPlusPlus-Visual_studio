#pragma once
#include<string>
#include "Calculator.h"
using namespace std;



class Calculator
{
public:
	static int add(int num1, int num2);
	static int multiply(int num1, int num2);
	static int subtract(int num1, int num2);




	Calculator();
	~Calculator();

};

