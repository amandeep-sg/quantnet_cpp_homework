// Main.cpp
// Initialize a point, line and circle
// call print command of each instance
//
// author: amandeep singh gujral

#include <iostream>

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace std;
using namespace ADSINGH::CAD;

int main()
{
     // Does it print the right information even when derived classes do not have the Print() function?
     // Ans: Yes, because the print function internally calls a virtual ToString function.
     // And each derived class has ToString() member function
     Point p(1, 2);
     Line l(Point(2, 3), Point(4, 5));
     Circle c(p, 5);

     Shape *ptr;

     cout << endl;
     p.Print();
     l.Print();
     c.Print();
     ptr->Print();

     cout << endl;
     return 0;
}