using namespace std;
#include <iostream>
#include"calculator.h"
//#include "ConstractorOverload.h"

int main()
{
	calculator c1;
	cout << "thw sum of these int is " << c1.add(3, 5) << endl;
	cout << "thw sum of these int is " << c1.add(3, 5, 5) << endl;
	
//cout << "thw sum of these int is " << c1.add(3.2 , 5.2 , 5.2) << endl;
	cout << "thw sum of these int is " << c1.add("hello", "world") << endl;


	return 0;
}
