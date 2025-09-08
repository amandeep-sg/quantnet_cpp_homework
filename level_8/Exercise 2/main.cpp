// main.cpp
// create tuple to store a name, age and length of a person
// create print function to print the tuble in console
// increment the age of a person
// author: amandeep singh gujral

#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>

using namespace std;

void print(const boost::tuple<string, int, double> &source)
{

    cout << "Name: " << source.get<0>() << endl;
    cout << "Age: " << source.get<1>() << endl;
    cout << "Length: " << source.get<2>() << endl;
    cout << endl;
};

int main()
{

    // typedef of Person tuple that contains name, age and length
    typedef boost::tuple<string, int, double> Person;

    // create few instance of Person tuple
    Person p1 = boost::make_tuple(string("Case"), 35, 176.00);
    Person p2 = boost::make_tuple(string("Price"), 32, 166.00);
    Person p3 = boost::make_tuple(string("Adler"), 40, 186.00);

    // print instance of Person tuple
    print(p1);
    print(p2);
    print(p3);

    // increase the age of p2
    p2.get<1>()++;
    cout << "age of p2 is increase by 1 year: " << endl;
    print(p2);

    return 0;
}