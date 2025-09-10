// main.cpp
// create pointers of shared_ptr for pointing to instances of Point, Line & Circle
// Assign the shared_ptr to array of shared_ptr
// print the elements of the array using for loop
//
// author: amandeep singh gujral

#include <iostream>
#include <boost/shared_ptr.hpp>

#include "container/Array.hpp"
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

     {
          int size = 3;
          ShapeArray arr(size);
          arr[0] = p1;
          arr[1] = p2;
          arr[2] = p3;

          for (int i = 0; i < size; i++)
          {
               cout << arr[i]->ToString() << endl;
          }

          cout << p1.use_count() << endl;
          cout << p2.use_count() << endl;
          cout << p3.use_count() << endl;
     }

     cout << endl;

     // deletion fo the array is deleted automatically. No need to call delete[] arr
     // deletion of the shapes is deleted automatically. No need to call delete p1
     // Note: After the destruction, the shared_pointers that shared ownership with *this,
     // if any, will report a use_count() that is one less than its previous value. url: https://en.cppreference.com/w/cpp/memory/shared_ptr/~shared_ptr.html

     cout << p1.use_count() << endl;
     cout << p2.use_count() << endl;
     cout << p3.use_count() << endl;

     cout << endl;

     return 0;
}
