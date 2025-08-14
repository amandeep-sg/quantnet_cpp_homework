// Line.hpp
// program define the line class with a start and an end point
// line class has default constructor, constructor with start and end point, plus a copy constructor
// declare getter to get start and end point
// declare setter to update start and end point
// declare ToString() to get the description of the line
// declare Length() to get the length of the line
// declare operator= overload
// declare operator<< overload to cout
//
// author: amandeep singh gujral

#ifndef Line_hpp
#define Line_hpp

#include <string>
#include <ostream>

#include "Point.hpp"

class Line
{
private:
    Point start_point;
    Point end_point;

public:
    Line();                                     // default constructor
    Line(Point &start_point, Point &end_point); // constructor with start and end point
    Line(const Line &other);                    // copy constructor

    ~Line(); // destructor

    const Point &Start_Point() const; // get start point of the line
    const Point &End_Point() const;   // get end point of the line

    void Start_Point(Point &p); // update start point of the line
    void End_Point(Point &p);   // update end point of the line

    double Length() const; // returns length of the line

    Line &operator=(const Line &source); // assign coordinates of start and end point of the source line

    string ToString() const; // return description of the line ex. Line Start Point(1, 0) and Line End Point(2, 1)
};

// global function for << operator, outside the class defination
ostream &operator<<(ostream &os, const Line &source);

#endif