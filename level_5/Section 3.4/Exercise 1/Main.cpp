// Main.cpp
// program to showcase the reduction in the constructor call by using colon syntes in the 
// defacult contructor, constructor with initial values, copy constructor and assignment operator
//
// author: amandeep singh gujral

#include <iostream>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace std;
using namespace ADSINGH::CAD;

int main()
{
     // using the colon syntex in the constructor of Line and Circle class
     // reduces the number of constructor calls as the =operator overload function is not called ex.
     // two constructor calls are saves while instantianting line l
     // one constructor call is saved while instantiating circle c
     // this is becaue construction of Point and Initialization of Line happen in one operation
     
     Line l;
     Circle c;

     return 0;
}