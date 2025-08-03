// Point.cpp
// program to define the constructor, destructor and member functions of class Point
//
// author: amandeep singh gujral

#include <iostream> // cpp style I/O
#include <sstream>  // string stream
#include <cmath>    // math

#include "Point.hpp" // Point header

using namespace std;

Point::Point() : point_x(0.00), point_y(0.00) {}; // initialise Point instance with x = 0.00 and y = 0.00

double Point::GetX() { return point_x; } // return x coordinate of the point
double Point::GetY() { return point_y; } // return y coordinte of the point

void Point::SetX(double x) { this->point_x = x; } // set the x coordinte of the point
void Point::SetY(double y) { this->point_y = y; } // set the y coordinate of the point

double Point::DistanceOrigin() // return distance of the point from origin
{
    return sqrt(point_x * point_x + point_y * point_y);
}

double Point::DistancePoint(const Point &p) // return distance between two points
{
    return sqrt(pow((point_x - p.point_x), 2) + pow((point_y - p.point_y), 2));
}

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