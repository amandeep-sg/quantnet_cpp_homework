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
     // without declaring the destructor of Shape class virtual, the destructor of derived classes are not getting called
     // after making the destructor of Shape class virtual, the destructor of derived class were called followed by destructors of base class i.e. shape
     Shape *shapes[4];
     shapes[0] = new Shape;
     shapes[1] = new Point;
     shapes[2] = new Line;
     shapes[3] = new Circle;
     for (int i = 0; i != 4; i++)
          delete shapes[i];
     return 0;
}