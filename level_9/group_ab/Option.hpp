// Option.hpp
// declare the base class option
//
// author: amandeep singh gujral

#ifndef OPTION_HPP
#define OPTION_HPP
#include <vector>
#include <any>

#include "Enum.hpp"

using namespace std;

namespace INSTRUMENT
{
    namespace OPTION
    {
        class Option
        {
        public:
            Option();
            Option(const Option &source);
            virtual ~Option();

            Option &operator=(const Option &source);
            virtual vector<double> Params() const = 0;
            virtual void Params(const Param name, const double value) = 0;
        };
    }
}

#endif