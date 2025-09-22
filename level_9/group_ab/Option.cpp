// Option.cpp
// define the Option class
//
// author: amandeep singh gujral

#include "Option.hpp"

namespace INSTRUMENT
{
    namespace OPTION
    {
        Option::Option() {};
        Option::Option(const Option &source) {};
        Option::~Option() {};

        Option &Option::operator=(const Option &source)
        {
            return *this;
        }
    }
}