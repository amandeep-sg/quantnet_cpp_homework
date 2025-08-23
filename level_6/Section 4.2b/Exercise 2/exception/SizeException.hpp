// SizeException.cpp
// program to declare size exception class
// thrown if size of two arrays is not same
//
// author: amandeep singh gujral

#ifndef SizeException_hpp
#define SizeException_hpp

#include <string>
#include "ArrayException.hpp"

namespace ADSINGH
{
    namespace EXCEPTION
    {
        class SizeException : public ArrayException
        {
        private:
            int s1;
            int s2;

        public:
            SizeException();                                             // default cosntructor
            SizeException(const unsigned int s1, const unsigned int s2); // constructor initialised with s1 and s2 size arguments
            SizeException(const SizeException &source);                  // copy constructor

            ~SizeException(); // destructor

            SizeException &operator=(const SizeException &source); // operator== overlaod

            std::string GetMessage() const; // return error message
        };
    }
}

#endif