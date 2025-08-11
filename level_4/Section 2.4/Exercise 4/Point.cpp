// Point.cpp
// program to define the constructor, destructor and member functions of class Point
//
// author: amandeep singh gujral

#include <iostream> // cpp style I/O
#include <sstream>  // string stream
#include <cmath>    // math
#include <ostream>  //cpp style output stream

#include "Point.hpp" // Point header

using namespace std;

Point::Point() : point_x(0.00), point_y(0.00) // initialise Point instance with x = 0.00 and y = 0.00
{
    // cout << "Constructor called: New point is created!" << endl;
};

Point::Point(double x, double y) : point_x(x), point_y(y) // overload constructor to initialize with values x & y
{
    // cout << "Constructor called: New point is created!" << endl;
};

Point::Point(const Point &other) // copy constructor
{
    point_x = other.point_x;
    point_y = other.point_y;
    // cout << "Constructor called: " << ToString() << " copied!" << endl;
}

double Point::X() const { return point_x; } // return x coordinate of the point
double Point::Y() const { return point_y; } // return y coordinte of the point

void Point::X(double x) { this->point_x = x; } // set the x coordinte of the pointNew
void Point::Y(double y) { this->point_y = y; } // set the y coordinate of the point

double Point::Distance() const // return distance of the point from origin
{
    return sqrt(point_x * point_x + point_y * point_y);
}

double Point::Distance(const Point &other) const // return distance between two points
{
    return sqrt(pow((point_x - other.point_x), 2) + pow((point_y - other.point_y), 2));
}

string Point::ToString() const // return string description of the point ex. Point(1.02, 2.33)
{
    stringstream ss;
    ss << "Point(" << point_x << ", " << point_y << ")";
    return ss.str();
}

// define unary operator
Point Point::operator-() const // negate the coordinated of the point
{
    return Point(-point_x, -point_y);
}

// define binary operators
Point Point::operator+(const Point &other) const // add the coordinates of the point
{
    return Point(point_x + other.point_x, point_y + other.point_y);
}

// define assignment operators
Point &Point::operator=(const Point &source) // assign the coordinates of a point to other point.
{
    point_x = source.point_x;
    point_y = source.point_y;
    return *this;
}

Point &Point::operator*=(const double factor)
{
    point_x *= factor;
    point_y *= factor;
    return *this;
}

// define comaprison operator ==
bool Point::operator==(const Point &other)
{
    if (point_x == other.point_x && point_y == other.point_y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// define global function to scale the coordinated by a factor using *
Point operator*(const Point &p, const double factor)
{
    return Point(p.point_x * factor, p.point_y * factor);
}

Point operator*(const double factor, const Point &p)
{
    return p * factor;
}

ostream &operator<<(ostream &os, const Point &source) // overload << operator function defination
{
    os << "point ("<<source.point_x<<", "<<source.point_y<<")";
    return os;
}

// destructor
Point::~Point()
{
    // cout << ToString() << " is destroyed!" << endl;
}
