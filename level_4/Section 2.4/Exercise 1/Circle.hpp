// Circle.hpp
// program define the Circle class with a center point and raidus
// Circle class has default constructor, constructor with start and end point, plus a copy constructor
// declare getter to get center point and raidus of the circle
// declare setter to update center point and raidus
// declare ToString() to get the description of the Circle
// declare diameter(), area() and Circumference() to get respetive values
// declare operator= overload
//
// author: amandeep singh gujral

#ifndef Circle_hpp
#define Circle_hpp
#define _USE_MATH_DEFINES

#include <string>
#include "Point.hpp"

class Circle
{
private:
    Point center_point;
    double raidus;

public:
    Circle();                                    // default constructor
    Circle(Point &center_point, double raidus); // constructor with center point and raidus
    Circle(const Circle &other);                 // copy constructor

    ~Circle(); // destructor

    Point Center_Point() const;   // get start point of the circle
    double Raidus() const;        // get raidus of the circle
    double Diameter() const;      // get diameter of the circle
    double Area() const;          // get area of the circle
    double Circumference() const; // get the circumference of the circle

    void Center_Point(Point &p); // update center point of the circle
    void Raidus(double &r);      // update raidus of the circle

    Circle &operator=(const Circle &source); //assignment operator

    string ToString() const; // return description of the Circle ex. Circle Start Point(1, 0) and Circle End Point(2, 1)
};

#endif