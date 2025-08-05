// Line.hpp
// program define the line class with a start and an end point
// line class has default constructor, constructor with start and end point, plus a copy constructor
// declare getter to get start and end point
// declare setter to update start and end point
// declare ToString() to get the description of the line
//  declare Length() to get the length of the line
//
// author: amandeep singh gujral

#ifndef Line_hpp
#define Line_hpp

#include <string>
#include "Point.hpp"

class Line
{
private:
    Point start_point;
    Point end_point;

public:
    Line();                                   // default constructor
    Line(Point &start_point, Point &end_point); // constructor with start and end point
    Line(const Line &other);                  // copy constructor

    Point Start_Point() const; // get start point of the line
    Point End_Point() const;   // get end point of the line

    void Start_Point(Point &p); // update start point of the line
    void End_Point(Point &p);   // update end point of the line

    double Length() const; // returns length of the line

    string ToString() const; // return description of the line ex. Line Start Point(1, 0) and Line End Point(2, 1)
};

#endif