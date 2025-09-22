// EuropeanOption.hpp
// declare the european option class wihich takes in data members and compute price and greeks of the option
//
// author: amandeep singh gujral

#ifndef EUROPEAN_OPTION_HPP
#define EUROPEAN_OPTION_HPP

#include <string>
#include <vector>

#include "Option.hpp"
#include "Enum.hpp"

using namespace std;

namespace INSTRUMENT
{
    namespace OPTION
    {
        class EuropeanOption : public Option
        {
        private:
            void init();                             // set default values for data member
            void copy(const EuropeanOption &source); // copy the valus of data members

            double n(double x) const; // pdf
            double N(double x) const; // cdf

            double CallPrice(double r, double K, double T, double sig, double b, double S) const; // price of call option
            double PutPrice(double r, double K, double T, double sig, double b, double S) const;  // price of put option
            double DeltaCall(double r, double K, double T, double sig, double b, double S) const; // delta of call option
            double DeltaPut(double r, double K, double T, double sig, double b, double S) const;  // delta of put option
            double Gamma(double r, double K, double T, double sig, double b, double S) const;     // gamma of put/call option

        private:
            // data members
            double r;          // risk-free interest rates
            double K;          // strike price
            double T;          // time to maturity
            double sig;        // volatility
            double b;          // cost to carry
            double S;          // spot price
            string optionType; // call or put flag

        public:
            // constructors & member functions
            EuropeanOption();                                                                                                                                // default constructor
            EuropeanOption(const double r, const double K, const double T, const double sig, const double b, const double S, const string optionType = "C"); // constructor with initialial parameter
            EuropeanOption(const EuropeanOption &source);                                                                                                    // copy constructor
            ~EuropeanOption();

            EuropeanOption &operator=(const EuropeanOption &source); // assignment operator

            // getters and setters
            vector<double> Params() const override;                     // get a vectors of data members
            void Params(const Param name, const double value) override; // set the value of the data member
            void Params(vector<double> &data);                          // set the values of the data members

            // option price
            double Price() const;                                                       // compute price of the option
            vector<double> Price(const vector<vector<double>> &optionDataMatrix) const; // takes matrix of input params and return option price vector

            // greeks
            double Delta() const;                                                       // compute delta of the option
            double Delta(const double divisor) const;                                   // compute delta numerically using divided differance method
            vector<double> Delta(const vector<vector<double>> &optionDataMatrix) const; // take matrix of input params and return option delta vector
            double Gamma() const;                                                       // compute gamma of the option
            double Gamma(const double divisor) const;                                   // compute gamma numerically using divide differance methor
            vector<double> Gamma(const vector<vector<double>> &optionDataMatrix) const; // take matrix of input params and return option gamma vector

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