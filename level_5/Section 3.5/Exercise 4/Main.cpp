// Main.cpp
// Initialise shapes array of size 3
// assign shape, point and line to each element of shapes using new operator
// for loop to delete each elemet of the array
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
     // What implementation did you give the Draw() function in Shape?
     // Ans: Draw is a PVMF in Shape class. It has not implementation

     // Try to create an instance of the Shape class. Is this possible?
     // Ans: No, instance of shape cannot be created as it is a abstract base class

     Shape *shapes[5];
     shapes[0] = new Line;
     shapes[1] = new Point;
     shapes[2] = new Point(3.4, 5.6);
     shapes[3] = new Circle;
     shapes[4] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));

     cout << endl;
     for (int i = 0; i != 5; i++)
          shapes[i]->Draw();
     cout << endl;
     for (int i = 0; i != 5; i++)
          delete shapes[i];
     cout << endl;
     return 0;
}