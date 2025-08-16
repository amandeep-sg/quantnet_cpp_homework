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
     Shape s;                          // Create shape.
     Point p(10, 20);                  // Create point.
     Line l(Point(1, 2), Point(3, 4)); // Create line.

     cout << endl;

     cout << s.ToString() << endl; // Print shape.
     cout << p.ToString() << endl; // Print point.
     cout << l.ToString() << endl; // Print line

     cout << endl;

     cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
     cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work? Ans: Yes, Point p has inherited the member function of Shape Class
     cout << "Line ID: " << l.ID() << endl;  // ID of the line. Does this work? Ans: Yes, Line l has inherited the member function of Shape Class

     cout << endl;

     Shape *sp;                      // Create pointer to a shape variable.
     sp = &p;                        // Point in a shape variable. Possible? Ans: Yes, as Point is the child class of parent Shape
     cout << sp->ToString() << endl; // What is printed? Ans: ID is printed as ToString() member function of base class is called

     cout << endl;

     // Create and copy Point p to new point.
     Point p2;
     p2 = p;
     cout << p2 << ", " << p2.ID() << endl; // Is the ID copied. Ans: Yes, the ID is copied

     //Is the ID copied,  if you do not call the base class assignment in point?. 
     //And: If we do not call the base class assignment in the point, the ID is not copied. Insted a new id is generated

     cout << endl;
     return 0;
}