// Point.hpp
// program to define point class with x & y coordinates.
// declare and overlaad getter, setter and distance functions
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
    Point(const Point &other);     // copy constructor

    ~Point(); // destructor

    double X(); // get value of x coordinate of a point
    double Y(); // get value of y coorfinate of a point

    void X(double x); // update the value of x coordinate of a point
    void Y(double y); // update the value of y coordinate of a point

    double Distance();       // return distance of the point from origin
    double Distance(Point &other); // return distance between two points

    string ToString(); // retunr string description of the point, syntax => Point(x, y)
};

#endif