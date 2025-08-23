// Main.cpp
// Initialise an array of type Array of size 3
// Assign Point to each element of array
// get and set the elements of the array
//
// author: amandeep singh gujral

#include <iostream>

#include "Shape.hpp"
#include "Array.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "OutOfBoundsException.hpp"
#include "ArrayException.hpp"

using namespace std;
using namespace ADSINGH::CAD;
using namespace ADSINGH::CONTAINER;

int main()
{
     Array<Point> points(3);
     points.SetElement(0, Point(1, 2));
     points.SetElement(1, Point(3, 4));
     points.SetElement(2, Point(5, 6));

     cout << endl;
     // In the main program, create an Array object and access an element that does not exist.
     // Run the program. What happens?
     // ans: the program terminates with error "terminating due to uncaught exception of type int"

     Array<Circle> circles(2);
     circles.SetElement(0, Circle(points[0], 5));
     circles.SetElement(1, Circle(points[1], 3));

     cout << endl;
     try
     {
          cout << points[5] << endl;
          cout << circles[3] << endl;
     }
     catch (ArrayException &err)
     {
          cout << err.GetMessage() << endl;
     }
     catch (...)
     {
          cout << "error: unhandled exception" << endl;
     }

     cout << endl;

     cout << points[2] << endl;
     cout << circles[1] << endl;
     return 0;
}