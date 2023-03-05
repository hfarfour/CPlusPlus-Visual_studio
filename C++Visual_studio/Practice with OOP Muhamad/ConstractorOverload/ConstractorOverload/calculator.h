#pragma once
using namespace std;
#include<string>
#include"calculator.h"


class calculator
{
public:

	int add(int num1, int num2);
	int add(int num1, int num2,int num3);
	float add(float num1, float num2, float num3);
	string add(string a, string b);



calculator();
~calculator();
};

