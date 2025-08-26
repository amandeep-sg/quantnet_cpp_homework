// PointArray.cpp
// define the constructor, destructor, data members and function memebers of class PointArray derived from base class Array
//
// author: amandeep singh gujral

#ifndef PointArray_cpp
#define PointArray_cpp

#include "Array.hpp"
#include "../cad/Point.hpp"

#include "PointArray.hpp"

using namespace ADSINGH::CAD;

namespace ADSINGH
{
    namespace CONTAINER
    {
        PointArray::PointArray() : Array<Point>() {};                               // default constructor
        PointArray::PointArray(const unsigned int size) : Array<Point>(size) {};    // constructor to instantiate array of size defined by client
        PointArray::PointArray(const PointArray &source) : Array<Point>(source) {}; // copy constructor
        PointArray::~PointArray() {};                                               // destructor

        PointArray &PointArray::operator=(const PointArray &source) // assigment operator overload
        {
            if (this == &source) // check if this and source are the same objects or not
            {
                return *this;
            }

            Array<Point>::operator=(source); // call assignment operator of the base class
            return *this;
        }

        const double PointArray::Length() const // compute and returns the sum of distance between all the points in a PointArray
        {
            double length = 0.00;                       // initialise the length
            for (int i = 0; i != this->Size() - 1; i++) // for loop is run till n-1
            {
                length += this->GetElement(i).Distance(this->GetElement(i + 1));
            }
            return length;
        }
    }
}

#endif