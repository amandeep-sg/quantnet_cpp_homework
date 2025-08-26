// OutOfBoundsException.cpp
// program to define the constructor, destrutor, memeber functions of OutOfBoundsException class
//
// author: amandeep singh gujral

#include <sstream>
#include "OutOfBoundsException.hpp"

using namespace std;

namespace ADSINGH
{
    namespace EXCEPTION
    {
        OutOfBoundsException::OutOfBoundsException() {};                                                                           // default constructor
        OutOfBoundsException::OutOfBoundsException(int index) : erroneous_index(index) {};                                         // constuctor instantiates with erroneous_index = index
        OutOfBoundsException::OutOfBoundsException(const OutOfBoundsException &other) : erroneous_index(other.erroneous_index) {}; // copy constructor

        OutOfBoundsException::~OutOfBoundsException() {}; // destructor

        OutOfBoundsException &OutOfBoundsException::operator=(const OutOfBoundsException &source) // assignment operator overload
        {
            ArrayException::operator=(source);
            erroneous_index = source.erroneous_index;
            return *this;
        }

        string OutOfBoundsException::GetMessage() const // return error message to the client
        {
            stringstream ss;
            ss << "error: index: " << erroneous_index << " is out of bound!";
            return ss.str();
        }
    }
}