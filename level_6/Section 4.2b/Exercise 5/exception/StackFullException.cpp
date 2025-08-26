// StackFullException.cpp
// program to define the constructor, destrutor, memeber functions of StackFullException class
//
// author: amandeep singh gujral

#include <sstream>
#include "StackFullException.hpp"

using namespace std;

namespace ADSINGH
{
    namespace EXCEPTION
    {
        StackFullException::StackFullException() {};                                                                           // default constructor
        StackFullException::StackFullException(const StackFullException &other){}; // copy constructor

        StackFullException::~StackFullException() {}; // destructor

        StackFullException &StackFullException::operator=(const StackFullException &source) // assignment operator overload
        {
            StackException::operator=(source);
            return *this;
        }

        string StackFullException::GetMessage() const // return error message to the client
        {
            stringstream ss;
            ss << "error: stack is full!";
            return ss.str();
        }
    }
}