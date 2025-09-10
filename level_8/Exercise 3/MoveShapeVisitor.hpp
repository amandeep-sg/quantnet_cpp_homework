// MoveShapeVisitor.hpp
//  declaration of MoveShapeVisitor to move the ShapeType varient by x ^ y defined by the user
//
// author: amandeep singh gujral

#ifndef MoveShapeVisitor_hpp
#define MoveShapeVisitor_hpp

#include <boost/variant.hpp>

#include "cad/Circle.hpp"
#include "cad/Line.hpp"
#include "cad/Point.hpp"

using namespace ADSINGH::CAD;

class MoveShapeVisitor : public boost::static_visitor<void>
{
private:
    double x_corr;
    double y_corr;

public:
    MoveShapeVisitor();
    MoveShapeVisitor(const double x, const double y);
    MoveShapeVisitor(const MoveShapeVisitor &source);

    ~MoveShapeVisitor();

    MoveShapeVisitor &operator=(const MoveShapeVisitor &source);

    void operator()(Point &source) const;
    void operator()(Line &source) const;
    void operator()(Circle &source) const;
};

#endif