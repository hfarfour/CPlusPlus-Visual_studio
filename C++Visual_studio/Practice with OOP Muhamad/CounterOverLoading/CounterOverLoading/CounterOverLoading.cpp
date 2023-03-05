using namespace std;
#include"Counter.h"
#include <iostream>

int main()
{
	int i =2;
	int j=4 ;
	cout << "the anwser is  " << i + j << endl;
	Counter c1(5);
	Counter c2(10);
	Counter c3 = ++c1;
	
	Counter c4 = --c2;
	cout << c1.getCount() << endl;
	cout << c2.getCount() << endl;
	cout << c3.getCount() << endl;
	cout << c4.getCount() << endl;
	Counter c5 = c1++;     // post fix
	cout << c5.getCount() << endl;

}

