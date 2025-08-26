// Main.cpp
// Initialise an array of type Array of size 3
// Assign Point to each element of array
// get and set the elements of the array
//
// author: amandeep singh gujral

#include <iostream>

#include "container/PointArray.hpp"

using namespace std;
using namespace ADSINGH::CAD;
using namespace ADSINGH::CONTAINER;

int main()
{

     // intstantiate numeric array of type Point
     PointArray pointArray1;

     // set values of numeric arrays
     for (int i = 0; i != pointArray1.Size(); i++)
     {
          pointArray1.SetElement(i, Point(i + 1, i + 1));
     }

     cout << "elements of array: " << pointArray1.Print() << endl;
     cout << "sum of distance between all points: " << pointArray1.Length() << endl;

     return 0;
}
