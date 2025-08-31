// main.cpp
// calculate the sum of elements of serial and associative containers using sum template function
//
// author: amandeep singh gujral

#include <iostream>
#include <vector>
#include <list>
#include <map>

#include "Sum.hpp"

using namespace std;

int main()
{
    // create a list of type double
    // print first and last element of the list using front and back function
    list<double> list_1;

    // add elements to the list
    for (int i = 0; i < 5; i++)
    {
        list_1.push_back((i + 1) * 2);
    }

    cout << "sum of all elements of list_1: " << Sum(list_1) << endl;
    cout << "sum of all elements of list_1 by passing begin & end iterator: " << Sum<list<double> >(list_1.begin(), list_1.end()) << endl;

    cout << endl;
    // create a vector of type double
    // access elements of the vector using index operator
    // grow the vector

    vector<double> vec_1;

    // add elements to the vector
    for (int i = 0; i < 5; i++)
    {
        vec_1.push_back((i + 1) * 1.25);
    }
    cout << "sum of all elements of vec_1: " << Sum(vec_1) << endl;
    cout << "sum of all elements of vec_1 by passing begin & end iterator:" << Sum<vector<double> >(vec_1.begin(), vec_1.end()) << endl;

    cout << endl;

    // create a map that maps strings to doubles
    // fill the map and calculate the sum of elements
    map<string, double> map_1;

    map_1["abc"] = 1.11;
    map_1["bcd"] = 1.21;
    map_1["cde"] = 1.31;
    map_1["def"] = 1.41;
    map_1["efg"] = 1.51;

    cout << "sum of all element of map: " << Sum(map_1) << endl;
    cout << "Sum fo all elements of map by passing begin & end iterator: " << Sum<string, double>(map_1.begin(), map_1.end()) << endl;

    return 0;
}