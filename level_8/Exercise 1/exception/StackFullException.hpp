// StackFullException.hpp
// program to declare an StackFullExecption class, thrown when index of array is out of range
//
// author: amandeep singh gujral

#ifndef StackFullException_hpp
#define StackFullException_hpp

#include <string>
#include "StackException.hpp"

using namespace ADSINGH::EXCEPTION;

namespace ADSINGH
{
    namespace EXCEPTION
    {
        class StackFullException : public StackException
        {
        public:
            StackFullException();                                // default constructor
            StackFullException(const StackFullException &other); // copy constructor

            ~StackFullException(); // destructor

            StackFullException &operator=(const StackFullException &source); // assignment operator overload

            std::string GetMessage() const; // returns the error message
        };
    }
}

#endif
