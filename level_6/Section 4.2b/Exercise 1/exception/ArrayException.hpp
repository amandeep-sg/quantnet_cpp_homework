// ArrayException.hpp
// program to declare an ArrayExceptions abstract base class, thrown when index of array is out of range
//
// author: amandeep singh gujral

#ifndef ArrayException_hpp
#define ArrayException_hpp

#include <string>

namespace ADSINGH
{
    namespace EXCEPTION // exception namespace nested within ADSINGH
    {
        class ArrayException
        {
        public:
            ArrayException();                            // default constructor
            ArrayException(const ArrayException &other); // copy constructor
            virtual ~ArrayException();                           // destructor

            ArrayException &operator=(const ArrayException &source); // assignment operator overload

            virtual std::string GetMessage() const = 0; // GetMessage PVMF
        };
    }
}

#endif