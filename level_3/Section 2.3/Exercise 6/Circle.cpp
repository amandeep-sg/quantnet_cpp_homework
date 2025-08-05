// Circle.cpp
// program to define the behaviour of constructor, destructor and member functions of class Circle
//
// author: amandeep singh gujral

#include <iostream>
#include <sstream>
#include "Point.hpp"
#include "Circle.hpp"

Circle::Circle() : center_point(Point()), raidus(0.00) // initialise Circle with raidus 0.00 and center point (0.00, 0.00)
{
    cout << "Constructor called: New Circle created!";
};

Circle::Circle(Point &c, double &r) : center_point(c), raidus(r) // overload the constructor to initialize Circle with point a & b
{
    cout << "Constructor called: New Circle created with center  " << c.ToString() << " and raidus " << r << endl;
};

Circle::Circle(const Circle &other) : center_point(other.center_point), raidus(other.raidus) // copy constructor
{
    cout << "Constructor called: " << other.ToString() << " copied!" << endl;
};

Point Circle::Center_Point() const // get start point of the Circle
{
    return center_point;
}

double Circle::Raidus() const // get end point of the Circle
{
    return raidus;
}

double Circle::Diameter() const // get the diameter of the circle
{
    return 2 * raidus;
}

double Circle::Area() const // get the area of the circle
{
    return M_PI * pow(raidus, 2);
}

double Circle::Circumference() const // get the circumference of the circle
{
    return 2 * M_PI * raidus;
}

void Circle::Center_Point(Point &p) // update start point of the Circle
{
    this->center_point = p;
}

void Circle::Raidus(double &r) // update end point of the Circle
{
    this->raidus = r;
}

string Circle::ToString() const // return desctiption of the Circle in string
{
    stringstream ss;
    ss << "Circle has center " << center_point.ToString() << " and raidus " << raidus << endl;
    return ss.str();
}

Circle::~Circle()
{
    cout << ToString() << " is destroyed" << endl;
}