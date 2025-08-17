// Main.cpp
// Initialize a point, line and circle
// call print command of each instance
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
     //Does it print the right information even when derived classes do not have the Print() function?
     //Ans: No, because the code doesnot compile as the compiler will consider the derived class as abstract class
     Point p(1, 2);
     Line l(Point(2, 3), Point(4, 5));
     Circle c(p, 5);

     cout << endl;
     p.Print();
     l.Print();
     c.Print();

     cout << endl;
     return 0;
}