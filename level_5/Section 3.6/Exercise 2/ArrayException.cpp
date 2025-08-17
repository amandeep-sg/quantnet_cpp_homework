// ArrayException.cpp
// program to define the ArrayException class

#include "ArrayException.hpp"

namespace ADSINGH
{
    namespace EXCEPTION
    {
        ArrayException::ArrayException() {};                            // default constructor
        ArrayException::ArrayException(const ArrayException &other) {}; // copy constructor
        ArrayException::~ArrayException() {};                           // destructor

        ArrayException &ArrayException::operator=(const ArrayException &source) // assignment operator overload
        {
            return *this;
        };
    }
}