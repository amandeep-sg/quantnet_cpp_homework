// main.cpp
// program to demonstrate the usage of stl
//  usage of vector, list and map containers are demonstrated
//
// author: amandeep singh gujral

#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
    // create a list of type double
    // print first and last element of the list using front and back function
    cout << "step-1: creat list" << endl;
    list<double> list_1;

    // add elements to the list
    for (int i = 0; i < 10; i++)
    {
        list_1.push_back((i + 1) * 1.5);
    }

    cout << "first element of the list1: " << list_1.front() << endl;
    cout << "second element of the list1: " << list_1.back() << endl;

    cout << endl;

    // create a vector of type double
    // access elements of the vector using index operator
    // grow the vector

    cout << "step-1: create a vector" << endl;
    vector<double> vec_1;

    // check size/capacity of the vector
    cout << "size of vec_1: " << vec_1.size() << endl;
    cout << "max size of vec_1: " << vec_1.max_size() << endl;
    cout << "capacity of vec_1: " << vec_1.capacity() << endl
         << endl;

    cout << "step-2: space received for 5 elements" << endl;
    vec_1.reserve(5);

    // check size/capacity of the vector after reserving space of 5 elements
    cout << "size of vec_1: " << vec_1.size() << endl;
    cout << "max size of vec_1: " << vec_1.max_size() << endl;
    cout << "capacity of vec_1: " << vec_1.capacity() << endl
         << endl;

    cout << "step-3: added 10 elements to the vector" << endl;

    // add elements to the vector
    for (int i = 0; i < 10; i++)
    {
        vec_1.push_back((i + 1) * 1.25);
    }

    // check size/capacity of the vector after adding 10 elements
    cout << "size of vec_1: " << vec_1.size() << endl;
    cout << "max size of vec_1: " << vec_1.max_size() << endl;
    cout << "capacity of vec_1: " << vec_1.capacity() << endl
         << endl;

    // print all the elements of the vector
    cout << "elements of vec_1: ";
    for (int i = 0; i < 10; i++)
    {
        cout << vec_1[i] << " ";
    }
    cout << endl;

    // clear the vector
    cout << "step-4: clear the vector" << endl;

    vec_1.clear();

    // check size/capacity of the vector after adding 10 elements
    cout << "size of vec_1: " << vec_1.size() << endl;
    cout << "max size of vec_1: " << vec_1.max_size() << endl;
    cout << "capacity of vec_1: " << vec_1.capacity() << endl
         << endl;

    // create a vector of predefined size
    // add element to the vector to grow the size
    cout << "step-1: create a vector" << endl;
    vector<double> vec_2(8);

    // check size/capacity of the vector
    cout << "size of vec_2: " << vec_2.size() << endl;
    cout << "max size of vec_2: " << vec_2.max_size() << endl;
    cout << "capacity of vec_2: " << vec_2.capacity() << endl
         << endl;

    cout << "step-2: add an element to the back of the vector" << endl;
    vec_2.push_back(23); // add element to vec_2 from the back

    // check size/capacity of the vector
    cout << "size of vec_2: " << vec_2.size() << endl;
    cout << "max size of vec_2: " << vec_2.max_size() << endl;
    cout << "capacity of vec_2: " << vec_2.capacity() << endl
         << endl;

    // clear the vector
    cout << "step-3: clear the vector" << endl;

    vec_2.clear();

    // check size/capacity of the vector after adding 10 elements
    cout << "size of vec_2: " << vec_2.size() << endl;
    cout << "max size of vec_2: " << vec_2.max_size() << endl;
    cout << "capacity of vec_2: " << vec_2.capacity() << endl
         << endl;

    // create a map that maps strings to doubles
    // fill the map and access elements using square bracket operator

    cout << "step-1: create a map" << endl;

    map<string, double> map_1;

    map_1["abc"] = 1.11;
    map_1["bcd"] = 1.21;
    map_1["cde"] = 1.31;
    map_1["def"] = 1.41;
    map_1["efg"] = 1.51;

    cout << "step-2: print values of the map" << endl;
    // print values of map using square bracket operator
    cout << "key | val" << endl;
    cout << "abc | " << map_1["abc"] << endl;
    cout << "bcd | " << map_1["bcd"] << endl;
    cout << "cde | " << map_1["cde"] << endl;
    cout << "def | " << map_1["def"] << endl;
    cout << "efg | " << map_1["efg"] << endl;

    return 0;
}