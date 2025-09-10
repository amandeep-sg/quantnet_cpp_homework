// CreateShape.hpp
// the function takes an integer as an argument and returns a ShapeType varient containing respective shape
// Throws exception for unmapped integers
//
// author: amandeep singh gujral

#ifndef CreateShape_hpp
#define CreateShape_hpp

#include <boost/variant.hpp>
#include <stdexcept>

#include "cad/Point.hpp"
#include "cad/Line.hpp"
#include "cad/Circle.hpp"

using namespace std;
using namespace ADSINGH::CAD;

typedef boost::variant<Point, Line, Circle> ShapeType;

// CreateShape function declaration
ShapeType CreateShape(const unsigned int num);

// CreateShape function defination
ShapeType CreateShape(const unsigned int num)
{
    ShapeType shape;
    switch (num)
    {
    case 1:
        shape = Point();
        break;
    case 2:
        shape = Line();
        break;
    case 3:
        shape = Circle();
        break;
    default:
        throw invalid_argument("error: invalid enum!");
    }
    return shape;
}

#endif