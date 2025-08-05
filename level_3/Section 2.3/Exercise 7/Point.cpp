// Point.cpp
// program to define the constructor, destructor and member functions of class Point
//
// author: amandeep singh gujral

#include <iostream> // cpp style I/O
#include <sstream>  // string stream
#include <cmath>    // math

#include "Point.hpp" // Point header

using namespace std;

Point::Point() : point_x(0.00), point_y(0.00) // initialise Point instance with x = 0.00 and y = 0.00
{
    cout << "Constructor called: New point is created!" << endl;
};

Point::Point(double x, double y) : point_x(x), point_y(y) // overload constructor to initialize with values x & y
{
    cout << "Constructor called: New point is created!" << endl;
};

Point::Point(const Point &other) // copy constructor
{
    point_x = other.point_x;
    point_y = other.point_y;
    cout << "Constructor called: " << ToString() << " copied!" << endl;
}

double Point::Distance() const // return distance of the point from origin
{
    return sqrt(point_x * point_x + point_y * point_y);
}

double Point::Distance(Point &other) const // return distance between two points
{
    return sqrt(pow((point_x - other.point_x), 2) + pow((point_y - other.point_y), 2));
}

string Point::ToString() const // return string description of the point ex. Point(1.02, 2.33)
{
    stringstream ss;
    ss << "Point(" << point_x << ", " << point_y << ")";
    return ss.str();
}

Point::~Point()
{
    cout << ToString() << " is destroyed!" << endl;
}