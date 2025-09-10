// Line.cpp
// program to define the behaviour of constructor, destructor and member functions of class Line
//
// author: amandeep singh gujral

#include <iostream>
#include <sstream>
#include <ostream>

#include "Point.hpp"
#include "Line.hpp"

using namespace std;

namespace ADSINGH
{
    namespace CAD
    {

        Line::Line() : Shape(), start_point(Point()), end_point(Point()) // initialise line with start point (0.00, 0.00) and end point (0.00, 0.00)
        {

            // cout << "Constructor called: New line created!";
        };

        Line::Line(const Point &a, const Point &b) : Shape(), start_point(a), end_point(b) // overload the constructor to initialize line with point a & b
        {
            // cout << "Constructor called: New line created with start " << a.ToString() << " and end " << b.ToString() << endl;
        };

        Line::Line(const Line &other) : Shape(other), start_point(other.start_point), end_point(other.end_point) // copy constructor
        {
            // cout << "Constructor called: " << other.ToString() << " copied!" << endl;
        };

        Point Line::Start_Point() const // get start point of the line
        {
            return start_point;
        }

        Point Line::End_Point() const // get end point of the line
        {
            return end_point;
        }

        void Line::Start_Point(Point &p) // update start point of the line
        {
            this->start_point = p;
        }

        void Line::End_Point(Point &p) // update end point of the line
        {
            this->end_point = p;
        }

        void Line::Draw() const // draw line in the cartesian plane
        {
            cout << "Draw line: " << *this << endl;
        }

        double Line::Length() const // calculate and return the lenght of the line
        {
            return start_point.Distance(end_point);
        }

        Line &Line::operator=(const Line &source)
        {
            Shape::operator=(source);
            start_point = source.start_point;
            end_point = source.end_point;
            return *this;
        }

        string Line::ToString() const // return desctiption of the line in string
        {
            stringstream ss;
            ss << "Line Start " << start_point << " | Line End " << end_point << " | Line  " << Shape::ToString();
            return ss.str();
        }

        ostream &operator<<(ostream &os, const Line &source) // <<operator overload to cout
        {
            os << "Line start " << source.start_point << " | " << "Line end " << source.end_point;
            return os;
        }

        Line::~Line()
        {
            // cout << "Destructor called: line destroyed with start " << start_point.ToString() << " and end " << end_point.ToString() << endl;
        }
    }
}