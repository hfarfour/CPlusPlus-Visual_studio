#include<string>
#include <iostream>
#include <iomanip>// important 
#include "Practice1.h"
using namespace std;

int main()
{
	/*string name;
	cout << "enter your name " << endl;
	getline(cin, name);
	cout << "yourname is  " << name << endl;

	const float e = 2.718;
	float price = 18.0;
	cout << setw(8) << e << endl;
	cout << left << setw(8)<<e << endl;
	cout << fixed << e << endl;
	cout << setw(6) << e << endl;*/




	
	/*int num;
	int limit;
	cout << "table of square " << endl;
	cout << "how hight to go " << endl;
	cout << "\n\numner     square\n";
	num = 1;
	while (num <= limit)
	{
		cout << setw(6) << num << setw(6) << num * num << endl;
		num++;
	}*/

	int sum = 0, num = 1;
	while (num <= 4)
	{
		sum += num;
		num++;
	}
	cout << sum << endl;
	return 0;
}
