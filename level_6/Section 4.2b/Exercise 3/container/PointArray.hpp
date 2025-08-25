// PointArray.hpp
// declare the constructor, destructor, data members and function members of class PointArray derived from base class Array
//
// author: amandeep singh gujral

#ifndef PointArray_hpp
#define PointArray_hpp

#include "Array.hpp"
#include "../cad/Point.hpp"

using namespace ADSINGH::CAD;

namespace ADSINGH
{
    namespace CONTAINER
    {
        class PointArray : public Array<Point>
        {
        public:
            PointArray();                         // default constructor
            PointArray(const unsigned int size);  // constructor to instantiate array of size defined by client
            PointArray(const PointArray &source); // copy constructor

            ~PointArray(); // destructor

            PointArray &operator=(const PointArray &source); // assignmen operator overload
            const double Length() const;                     // length function to return the sum of distance between all the points in a PointArray
        };
    }
}

#endif