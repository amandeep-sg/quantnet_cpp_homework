// Point.cpp
// program to define the constructor, destructor and member functions of class Point
//
// author: amandeep singh gujral

#include <iostream>
#include <sstream>
#include "Point.hpp"

using namespace std;

Point::Point() : point_x(0.00), point_y(0.00) {}; // initialise Point instance with x = 0.00 and y = 0.00

double Point::GetX() { return point_x; } // return x coordinate of the point
double Point::GetY() { return point_y; } // return y coordinte of the point

void Point::SetX(double x) { this->point_x = x; } // set the x coordinte of the point
void Point::SetY(double y) { this->point_y = y; } // set the y coordinate of the point

string Point::ToString() // return string description of the point ex. Point(1.02, 2.33)
{
    stringstream ss;
    ss << "Point(" << point_x << ", " << point_y << ")";
    return ss.str();
}

Point::~Point()
{
    cout << ToString() << "is destroyed" << endl;
}