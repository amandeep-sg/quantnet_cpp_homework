// Main.cpp
// cpp program to swap the value of two int variables
//
// author: amandeep singh gujral

#include <iostream>

using namespace std;

int main()
{
    int num1 = 123;
    int num2 = 456;

    cout << "num1: " << num1 << ", num2: " << num2 << endl;
    swap(num1, num2);
    cout << "num1: " << num1 << ", num2: " << num2 << endl;

    return 0;
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}