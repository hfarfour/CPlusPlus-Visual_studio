// TutorialWorkPageFive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;



int addNumberTo(int number)
{
    if (number == 1) return 1;
    return number + addNumberTo(number - 1);
}
int FindHihest(vector<int>& numbers, int index = 0)
{
    if (index == numbers.size() - 1)return numbers[index];
    int highestNumberSoFar = FindHihest(numbers, index + 1);
    return (numbers[index] > highestNumberSoFar) ? numbers[index] : highestNumberSoFar;
}


int main()
{
    cout << "the sum of number = " << addNumberTo(10) << endl;
    vector<int>numbers = { 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 };
    cout << "the Highest number is  =" << FindHihest(numbers) << endl;
}
