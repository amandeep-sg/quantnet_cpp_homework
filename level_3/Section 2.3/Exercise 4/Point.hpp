// Point.hpp
// program to define point class with x & y coordinates.
// declare getter and setter functions to get and set values for x & y
// declare distanceOrigin member function to calculate distnce of point from origin
// declare distancePoint member function to calculate distnce between two points
// declare ToString() funtion
//
// author: amandeep singh gujral

#ifndef Point_hhp
#define Point_hhp

#include <string>
using namespace std;

class Point
{
private:
    double point_x; // x coordinate of a point
    double point_y; // y coordinate of a point

public:
    Point();                   // constructor
    Point(double x, double y); // Overload constructor to initialize with value of x and y
    Point(const Point &other); // copy constructor

    ~Point(); // destructor

    double X() const; // get value of x coordinate of a point
    double Y() const; // get value of y coorfinate of a point

    void X(double x); // update the value of x coordinate of a point
    void Y(double y); // update the value of y coordinate of a point

    double Distance() const;             // return distance of the point from origin
    double Distance(Point &other) const; // return distance between two points

    string ToString() const; // return string description of the point, syntax => Point(x, y)
};

#endif