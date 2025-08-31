// main.cpp
// calculate the count of elements less than threshold using
// functor
// function
//
// author: amandeep singh gujral

#include <iostream>
#include <vector>
#include <list>
#include <map>

#include "IsSmaller.hpp"

using namespace std;
using namespace ADSINGH::FUNCTION_OBJECT;

// global function to compare elements of the serial container e.g. list to threshold
template <typename T>
bool less_than(T &value)
{
    T threshold = 3.00;
    return value < threshold;
}

int main()
{
    // create a list of type double
    // print first and last element of the list using front and back function
    list<double> list_1;

    // add elements to the list
    for (int i = 0; i < 10; i++)
    {
        list_1.push_back((i));
    }

    IsSmaller<double> less_than_five(5.00); // functor instance with value 4

    // use of global function
    cout << "count of elements less than 3.00: " << std::count_if(list_1.begin(), list_1.end(), less_than<double>) << endl;

    // use of functor
    cout << "count of elements less than 5.00: " << std::count_if(list_1.begin(), list_1.end(), less_than_five) << endl;

    return 0;
}