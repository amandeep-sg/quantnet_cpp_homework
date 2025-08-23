// SizeException.cpp
// programe to define the constructor, destructor, member function of SizeException class
//
// author: amandeep singh gurjal

#include <iostream>
#include <sstream>
#include "SizeException.hpp"

using namespace std;

namespace ADSINGH
{
    namespace EXCEPTION
    {
        SizeException::SizeException() {};
        SizeException::SizeException(const unsigned int s1, const unsigned int s2) : s1(s1), s2(s2) {};
        SizeException::SizeException(const SizeException &other) : s1(other.s1), s2(other.s2) {};

        SizeException::~SizeException(){};

        SizeException &SizeException::operator=(const SizeException &source)
        {
            s1 = source.s1;
            s2 = source.s2;
            return *this;
        }

        string SizeException::GetMessage() const
        {
            stringstream ss;
            ss << "Mismatch error: trying to add array of size " << s1 << " and " << s2 << "!";
            return ss.str();
        }
    }
}