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

using namespace std;
using namespace ADSINGH::CAD;
using namespace ADSINGH::CONTAINER;

int main()
{
     Array points(3);
     points.SetElement(0, Point(1, 2));
     points.SetElement(1, Point(3, 4));
     points.SetElement(2, Point(5, 6));

     cout << endl;
     // In the main program, create an Array object and access an element that does not exist.
     // Run the program. What happens?
     // ans: the program terminates with error "terminating due to uncaught exception of type int"

     try
     {
          cout << points[-1] << endl;
     }
     catch (int error_code)
     {
          if (error_code == -1)
               cout << "error: index is out of range" << endl;
     }
     catch (...)
     {
          cout << "error: unhandled exception" << endl;
     }

     cout << endl;
     cout<<points.Size()<< endl;

     cout << points[2] << endl;
}