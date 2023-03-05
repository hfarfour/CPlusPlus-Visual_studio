#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
// This program reads five numbers from the keyboard, and prints out the
// average and the maximum value
///////////////////////////////////////////////////////////////////////

double GetAverage(int IntArray[], int max);

int GetMax(int IntArray[], int Max);

int main()
{
	int Values[5];
	cout << "Enter five numbers : " << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> Values[i];
	}
	// Now we echo the input back to the user

	for (int i = 0; i < 5; i++)
	{
		cout << "Value [ " << i + 1 << "] is : " << Values[i] << endl;
	}
	// Now lets call a function to get the average:

	cout << "The average is " << GetAverage(Values, 5) << endl;

	// Finally we can get the maximum value

	cout << "The Maximum value is : " << GetMax(Values, 5) << endl;
	return 0;
}


double GetAverage(int IntArray[], int max)
{
	double temp = 0.0;

	for (int i = 0; i < max; i++)
		temp += IntArray[i];
	temp /= max;

	return temp;

} // End of GetAverage

int GetMax(int IntArray[], int Max)
{
	int Biggest = 0;

	for (int i = 0; i < Max; i++)
		if (Biggest < IntArray[i])
			Biggest = IntArray[i];
	return Biggest;
} // End of GetMax()


