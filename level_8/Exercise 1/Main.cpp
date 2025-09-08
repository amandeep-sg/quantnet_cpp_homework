// Main.cpp
// Instantiate 3 Stack of type Int and size 4
// push and pop the elements of the stack
// try use of copy constructor and assignment operator
//
// author: amandeep singh gujral

#include <iostream>
#include <boost/shared_ptr.hpp>

#include "container/Stack.hpp"
#include "cad/Shape.hpp"
#include "cad/Point.hpp"
#include "cad/Line.hpp"
#include "cad/Circle.hpp"

using namespace std;
using namespace ADSINGH::CONTAINER;
using namespace ADSINGH::CAD;

int main()
{

     typedef shared_ptr<Shape> ShapePtr;
     typedef Array<ShapePtr> ShapeArray;

     ShapePtr p1(new Point(1.0, 2.0));
     ShapePtr p2(new Line(Point(3.0, 4.0), Point(5.0, 6.0)));
     ShapePtr p3(new Circle(Point(0.0, 0.0), 10.0));

     int size = 3;
     ShapeArray arr(size);
     arr[0] = p1;
     arr[2] = p2;
     arr[3] = p3;

     for (int i = 0; i < size; i++)
     {
          cout << arr[i] << endl;
     }

     return 0;
}
