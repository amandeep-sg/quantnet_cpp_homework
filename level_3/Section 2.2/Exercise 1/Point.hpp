// Point.hpp
// program to define point class with x & y coordinates.
// declare getter and setter functions to get and set values for x & y
// declare ToString() funtion
//
// author: amandeep singh gujral

#ifndef Point_hhp
#define Point_hhp

#include <string> // cpp style string

using namespace std;

class Point
{
private:
    double point_x; // x coordinate of a point
    double point_y; // y coordinate of a point

public:
    Point();  // constructor
    ~Point(); // destructor

    double GetX();       // get value of x coordinate of a point
    double GetY();       // get value of y coorfinate of a point
    void SetX(double x); // update the value of x coordinate of a point
    void SetY(double y); // update the value of y coordinate of a point
    string ToString();   // return string description of the point, syntax => Point(x, y)
};

#endif