// main.cpp
// take an enum input from the user and return a variant containing a respective shape object
// try to assign the ShapeType variant to Line variable
// increment the points of the shape using visitor
//
// author: amandeep singh gujral

#include <iostream>
#include <boost/variant.hpp>
#include <stdexcept>

#include "cad/Point.hpp"
#include "cad/Line.hpp"
#include "cad/Circle.hpp"
#include "CreateShape.hpp"
#include "MoveShapeVisitor.hpp"

using namespace std;
using namespace ADSINGH::CAD;

typedef boost::variant<Point, Line, Circle> ShapeType;

int main()
{
    int num;
    cout << "Enter the enum, 1 => Point, 2 => Line, 3 => Circle: " << endl; // ShapeType defination
    cin >> num;

    // call CreateShape and pass on the num entered by the user.
    // assign it to my_shape variable and print it in the console
    ShapeType my_shape;
    try
    {
        my_shape = CreateShape(num);
        cout << my_shape << endl; // print my_shape to console
    }
    catch (const exception &e) // catch block to handle invalid_argument exception
    {
        cout << e.what() << endl;
    }
    catch (...) // catch block to hanlde unhandled exception
    {
        cout << "error: unhandled exception!" << endl;
    }

    // try to get value of the ShapeType varient and assign it to Line variable
    Line my_line;
    try
    {
        my_line = boost::get<Line>(my_shape);
    }
    catch (const boost::bad_get &e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "error: unhandled exception!" << endl;
    }

    cout << endl;
    // apply visitor and observe the change in the coordinates

    cout << "Before applying visitor: " << my_shape << endl;
    MoveShapeVisitor visitor(1.00, -2.00);

    boost::apply_visitor(visitor, my_shape);

    cout << "After applying visitor: " << my_shape << endl;

    return 0;
}