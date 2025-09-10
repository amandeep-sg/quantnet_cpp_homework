// MoveShapeVisitor.cpp
//  defination of MoveShapeVisitor to take in x& y values and move the ShapeType varient by x& y
//
// author: amandeep singh gujral

#include "MoveShapeVisitor.hpp"
#include "cad/Circle.hpp"
#include "cad/Line.hpp"
#include "cad/Point.hpp"

using namespace ADSINGH::CAD;

MoveShapeVisitor::MoveShapeVisitor() : x_corr(0.00), y_corr(0.00) {};

MoveShapeVisitor::MoveShapeVisitor(const double x, const double y) : x_corr(x), y_corr(y) {};

MoveShapeVisitor::MoveShapeVisitor(const MoveShapeVisitor &source) : x_corr(source.x_corr), y_corr(source.y_corr) {};

MoveShapeVisitor::~MoveShapeVisitor() {};

MoveShapeVisitor &MoveShapeVisitor::operator=(const MoveShapeVisitor &source)
{
    x_corr = source.x_corr;
    y_corr = source.y_corr;
    return *this;
}

void MoveShapeVisitor::operator()(Point &source) const
{
    source.X(source.X() + x_corr);
    source.Y(source.Y() + y_corr);
}

void MoveShapeVisitor::operator()(Line &source) const
{
    Point start = source.Start_Point();
    Point end = source.End_Point();

    this->operator()(start);
    this->operator()(end);

    source.Start_Point(start);
    source.End_Point(end);
}

void MoveShapeVisitor::operator()(Circle &source) const
{
    Point center = source.Center_Point();
    
    this->operator()(center);

    source.Center_Point(center);
}