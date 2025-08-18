// Point.hpp
// program to define point class with x & y coordinates.
// declare and overload getter, setter and distance functions
// make getter and distance functions const
// declare ToString() funtion
//
// author: amandeep singh gujral

#ifndef Point_hhp
#define Point_hhp

#include <string>
#include <ostream>

#include "Shape.hpp"

using namespace std;

namespace ADSINGH
{
    namespace CAD
    {
        class Point : public Shape
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

            const void Draw();                               // draw point in the cartesian plane
            double Distance() const;                   // return distance of the point from origin
            double Distance(const Point &other) const; // return distance between two points

            string ToString() const; // return string description of the point, syntax => Point(x, y)

            // unary operator declaration
            Point operator-() const; // negate the coordinates

            // binary operator declarations
            Point operator+(const Point &Point) const; // add two coordinates

            // assignment operator declaration
            Point &operator=(const Point &source);  // assign coordinates
            Point &operator*=(const double factor); // scale the coordinates

            // comparison operator declaration
            bool operator==(const Point &other); // compare two points

            // friend function for * operator
            friend Point operator*(const double factor, const Point &p);
            friend Point operator*(const Point &p, const double factor);

            // friend function for << operator, inside the class defination
            friend ostream &operator<<(ostream &os, const Point &source);
        };
    }
}

#endif