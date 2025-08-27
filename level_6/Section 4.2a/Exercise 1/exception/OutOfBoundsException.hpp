// OutOfBoundsException.hpp
// program to declare an OutOfBoundsExecption class, thrown when index of array is out of range
//
// author: amandeep singh gujral

#ifndef OutOfBoundsException_hpp
#define OutOfBoundsException_hpp

#include <string>
#include "ArrayException.hpp"

using namespace ADSINGH::EXCEPTION;

namespace ADSINGH
{
    namespace EXCEPTION
    {
        class OutOfBoundsException : public ArrayException
        {
        private:
            int erroneous_index;

        public:
            OutOfBoundsException();                                  // default constructor
            OutOfBoundsException(const int index);                         // constructor with index argument as initial value
            OutOfBoundsException(const OutOfBoundsException &other); // copy constructor

            ~OutOfBoundsException(); // destructor

            OutOfBoundsException &operator=(const OutOfBoundsException &source); // assignment operator overload

            std::string GetMessage() const; // returns the error message
        };
    }
}

#endif
