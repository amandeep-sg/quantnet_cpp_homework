// StackEmptyException.hpp
// program to declare an StackEmptyExecption class, thrown when index of array is out of range
//
// author: amandeep singh gujral

#ifndef StackEmptyException_hpp
#define StackEmptyException_hpp

#include <string>
#include "StackException.hpp"

using namespace ADSINGH::EXCEPTION;

namespace ADSINGH
{
    namespace EXCEPTION
    {
        class StackEmptyException : public StackException
        {
        public:
            StackEmptyException();                                  // default constructor
            StackEmptyException(const StackEmptyException &other); // copy constructor

            ~StackEmptyException(); // destructor

            StackEmptyException &operator=(const StackEmptyException &source); // assignment operator overload

            std::string GetMessage() const; // returns the error message
        };
    }
}

#endif
