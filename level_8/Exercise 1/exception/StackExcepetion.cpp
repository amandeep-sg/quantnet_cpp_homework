// StackException.cpp
// program to define the StackException class

#include "StackException.hpp"

namespace ADSINGH
{
    namespace EXCEPTION
    {
        StackException::StackException() {};                            // default constructor
        StackException::StackException(const StackException &other) {}; // copy constructor
        StackException::~StackException() {};                           // destructor

        StackException &StackException::operator=(const StackException &source) // assignment operator overload
        {
            return *this;
        };
    }
}