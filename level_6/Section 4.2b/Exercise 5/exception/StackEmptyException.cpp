// StackEmptyException.cpp
// program to define the constructor, destrutor, memeber functions of StackEmptyException class
//
// author: amandeep singh gujral

#include <sstream>
#include "StackEmptyException.hpp"

using namespace std;

namespace ADSINGH
{
    namespace EXCEPTION
    {
        StackEmptyException::StackEmptyException() {};                                 // default constructor
        StackEmptyException::StackEmptyException(const StackEmptyException &other) {}; // copy constructor

        StackEmptyException::~StackEmptyException() {}; // destructor

        StackEmptyException &StackEmptyException::operator=(const StackEmptyException &source) // assignment operator overload
        {
            StackException::operator=(source);
            return *this;
        }

        string StackEmptyException::GetMessage() const // return error message to the client
        {
            stringstream ss;
            ss << "error: stack is empty!";
            return ss.str();
        }
    }
}