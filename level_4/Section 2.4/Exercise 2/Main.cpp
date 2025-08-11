// Main.cpp
// program to Ask the user for the x-coordinate and y-coordinates of two point
// set the coordinates entered by the user using the setter functions
// print the description of the point returned by the ToString() function
// print the point coordinates using the get functions
// print the distance of both the points from origin
// print the distance between the two points
//
// author: amandeep singh gujral

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace std;

int main()
{
     // test -, + and = operators of Point class
     Point point_a(1, 1); // create a point with x-coordinate = 1 and y-coordinate = 1
     cout << "Point_a: " << point_a << endl;

     Point point_b(3, 3); // create a point with x-coordinate = 3 and y-coordinate = 3
     cout << "Point_b: " << point_b << endl;

     point_b = point_b + (-point_a); // add coordinates of point_b and (-point_a)
     cout << "Modified Point_b: " << point_b << endl
          << endl;

     // test * and *= operators of Point class
     cout << "scale point_a by factor of 4 (without modifying point_a): " << (4 * point_a) << endl; // scale the value of point_a without modifying it
     cout << "Point_a: " << point_a << endl;
     cout << "scale point_a by factor of 5 (by modifying point_a): " << (point_a *= 5) << endl
          << endl; // scale the value of point_a with modifying it

     // test == operator of Point class
     cout << "Is point_a equal to point_b?" << endl;
     cout << "Ans: " << (point_a == point_b ? "Yes" : "No") << endl
          << endl;

     // test = operator of Line class
     Line line_a(point_a, point_b);
     Line line_b;

     cout << "original line_a: " << line_a << endl;
     cout << "original line_b: " << line_b << endl;

     line_b = line_a; // assign start and end point of line a to line b
     cout << "modified line_b: " << line_b << endl
          << endl;

     // test = operator of Circle class
     Circle circle_a(point_a, 10.00);
     Circle circle_b;

     cout << "original circle_a: " << circle_a << endl;
     cout << "original circle_b: " << circle_b << endl;

     circle_b = circle_a; // assign center point and raidus of circle a to circle b
     cout << "modified circle_b: " << circle_b << endl;

     return 0;
}