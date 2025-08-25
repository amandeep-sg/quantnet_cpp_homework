// Main.cpp
// Initialise an array of type Array of size 3
// Assign Point to each element of array
// get and set the elements of the array
//
// author: amandeep singh gujral

#include <iostream>

#include "container/Array.hpp"
#include "container/NumericArray.hpp"

#include "cad/Shape.hpp"
#include "cad/Point.hpp"
#include "cad/Line.hpp"
#include "cad/Circle.hpp"

#include "exception/ArrayException.hpp"
#include "exception/OutOfBoundsException.hpp"
#include "exception/SizeException.hpp"

using namespace std;
using namespace ADSINGH::CAD;
using namespace ADSINGH::CONTAINER;

int main()
{

     // instantiate numeric array of type double;
     NumericArray<double> doubleArray2;
     NumericArray<double> doubleArray3;
     NumericArray<double> doubleArray4;
     NumericArray<double> doubleArray5(6);

     // intstantiate numeric array of type Point
     NumericArray<Point> pointArray1;
     NumericArray<Point> pointArray2;
     NumericArray<Point> pointArray3;

     // set values of numeric arrays
     for (int i = 0; i != doubleArray2.Size(); i++)
     {
          doubleArray2.SetElement(i, (i + 1) * 2);
          doubleArray3.SetElement(i, (i + 1) * 1.5);
          pointArray1.SetElement(i, Point(i + 1, i + 1));
          pointArray2.SetElement(i, Point((i + 1) * 2, (i + 1) * 2));
     }

     cout << endl;

     // addition of two double arrays of same size and assiging it to third array
     doubleArray4 = doubleArray2 + doubleArray3;
     cout << "Elements of array 4: " << doubleArray4.Print() << endl;

     cout << endl;

     // scaling of an array by a factor
     cout << "Elements of array 2 before scaling: " << doubleArray2.Print() << endl;
     doubleArray2 * 2;
     cout << "Elements of array 2 after scaling: " << doubleArray2.Print() << endl;

     cout << endl;

     // addition of two double arrays of different size and assigning it to third double array
     try
     {
          doubleArray4 = doubleArray2 + doubleArray5;
     }
     catch (ArrayException &exp)
     {
          cout << exp.GetMessage() << endl;
     }
     catch (...)
     {
          cout << "error: unhandeled exception" << endl;
     }

     cout << endl;

     // dot product of two double arrays of same size

     cout << "dot product of array 3 & array 2: " << doubleArray3.DotProduct(doubleArray2) << endl;

     cout << endl;

     // dot product of two double arrays of different size
     try
     {
          cout << doubleArray2.DotProduct(doubleArray5) << endl;
     }
     catch (ArrayException &exp)
     {
          cout << exp.GetMessage() << endl;
     }
     catch (...)
     {
          cout << "error: unhandeled exception" << endl;
     }

     cout << endl;

     // adding two point arrays and assigning it to third point array
     pointArray3 = pointArray1 + pointArray2;
     cout <<"elements of point array 3: " <<pointArray3.Print() << endl;

     cout << endl;

     // scaling point array with a factor

     cout << "Elements of array 2 before scaling: " << pointArray2.Print() << endl;
     pointArray2 * 2;
     cout << "Elements of array 2 after scaling: " << pointArray2.Print() << endl;

     cout << endl;

     // what assumptions do you make about the type used as template argument?
     // type which support numeric opertion e.g. double, int, etc should be used

     // Can you create a numeric array with Point objects
     // Yes, the numeric array of type Point can be instantiated
     // However, the dot cannot be computed as it is not defined in the Point class

     return 0;
}
