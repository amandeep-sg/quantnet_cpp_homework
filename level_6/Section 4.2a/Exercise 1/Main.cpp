// Main.cpp
// Instantiate an array of type Point of size 3
// instantiate an array of type Circle of size 2
// Assign Point to each element of points array
// Assign Circle to each element of circles array
// get and set the elements in the array
//
// author: amandeep singh gujral

#include <iostream>

#include "./container/Array.hpp"

#include "./cad/Shape.hpp"
#include "./cad/Point.hpp"
#include "./cad/Line.hpp"
#include "./cad/Circle.hpp"

#include "./exception/OutOfBoundsException.hpp"
#include "./exception/ArrayException.hpp"

using namespace std;
using namespace ADSINGH::CAD;
using namespace ADSINGH::CONTAINER;

int main()
{
     Array<Point> points(3); // array of size 3 of type Point
     points.SetElement(0, Point(1, 2));
     points.SetElement(1, Point(3, 4));
     points.SetElement(2, Point(5, 6));

     cout << endl;

     Array<Circle> circles(2); // array of size 2 of type Circle
     circles.SetElement(0, Circle(points[0], 5));
     circles.SetElement(1, Circle(points[1], 3));

     cout << endl;

     // try and catch to check error handling in case of index is out of range
     try
     {
          cout << points[5] << endl;
     }
     catch (ArrayException &err) // catch for array exceptions
     {
          cout << err.GetMessage() << endl;
     }
     catch (...) // catch for unhandled exception
     {
          cout << "error: unhandled exception" << endl;
     }

     cout << endl;

     cout << points[2] << endl;
     cout << circles[1] << endl;
     return 0;
}