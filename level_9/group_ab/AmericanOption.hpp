// AmericanOption.hpp
// declare AmericalOption class which takes in data members and computes prices and greeks of the option
//
// author: amandeep singh gujral

#ifndef AMERICAN_OPTION_HPP
#define AMERICAN_OPTION_HPP

#include <string>
#include <vector>

#include "Option.hpp"
#include "Enum.hpp"

using namespace std;

namespace INSTRUMENT
{
    namespace OPTION
    {
        class AmericanOption : public Option
        {
        private:
            void init();                             // set default values for data member
            void copy(const AmericanOption &source); // copy the valus of data members

            double CallPrice(double r, double K, double sig, double b, double S) const; // price of call option
            double PutPrice(double r, double K, double sig, double b, double S) const;  // price of put option

        private:
            // data members
            double S;          // spot price
            double K;          // strike price
            double r;          // return
            double sig;        // variance
            double b;          // cost of carry
            string optionType; // call or put

        public:
            AmericanOption();                                                                                                                // default constructor
            AmericanOption(const double r, const double K, const double sig, const double b, const double S, const string optionType = "C"); // constructor with initial parameters
            AmericanOption(const AmericanOption &source);
            ~AmericanOption();

            AmericanOption &operator=(const AmericanOption &source);

            // getters and setters
            vector<double> Params() const override;                     // get vector of data members
            void Params(const Param name, const double value) override; // set the value of the data member
            void Params(vector<double> &data);                          // set the values of the data members

            // option price
            double Price() const;                                                       // compute price of the option
            vector<double> Price(const vector<vector<double>> &optionDataMatrix) const; // takes matrix of input params and return option price vector

            // put-call parity
            bool Parity(const double callPrice, const double putPrice, const double tolerance = 0.00001) const; // check parity for given the given K, S & T
            double Parity(const double price) const;                                                            // compute call(or put) price for a given put(or call) price

            // switch option type call/put
            void toggle();                  // change the type of the option
            void toggle(const string type); // specify the type of the option
        };
    }
}

#endif