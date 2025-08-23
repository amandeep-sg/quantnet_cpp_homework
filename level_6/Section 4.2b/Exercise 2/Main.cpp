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
#include "SizeException.hpp"
#include "ArrayException.hpp"
#include "NumericArray.hpp"

using namespace std;
using namespace ADSINGH::CAD;
using namespace ADSINGH::CONTAINER;

int main()
{
     NumericArray<int> intArray1(3);
     NumericArray<int> intArray2;
     Array<double> doubleArray;
     cout << intArray1.Size() << endl;
     cout << intArray2.DefaultSize() << endl;
     cout << doubleArray.DefaultSize() << endl;
     intArray1.DefaultSize(15);
     cout << intArray1.DefaultSize() << endl;
     cout << intArray2.DefaultSize() << endl;
     cout << doubleArray.DefaultSize() << endl;

     try
     {
          NumericArray<int> intArray5;
          intArray5 = intArray2 + intArray2;
     }
     catch (ArrayException &exp)
     {
          cout << exp.GetMessage() << endl;
     }
     catch (...)
     {
          cout << "error: unhandeled exception" << endl;
     }
     return 0;
}

// following values are printed [Note: the default value (is hardcoded) = 5]
// 5
// 5
// 5
// 15
// 15
// 5
// Explanation:
// Static members are shared across all the instances of the class
// However, in case of templates, there are three instances 2 of class with type int and 1 of class with type double
// the static member of class with type int is updated in the program
// hence no impact on the instance of class with type double