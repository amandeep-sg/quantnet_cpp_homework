// StackException.hpp
// program to declare an StackExceptions abstract base class, thrown when index of Stack is out of range
//
// author: amandeep singh gujral

#ifndef StackException_hpp
#define StackException_hpp

#include <string>

namespace ADSINGH
{
    namespace EXCEPTION // exception namespace nested within ADSINGH
    {
        class StackException
        {
        public:
            StackException();                            // default constructor
            StackException(const StackException &other); // copy constructor
            ~StackException();                           // destructor

            StackException &operator=(const StackException &source); // assignment operator overload

            virtual std::string GetMessage() const = 0; // GetMessage PVMF
        };
    }
}

#endif