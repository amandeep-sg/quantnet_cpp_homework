// EuropeanOption.hpp
// declare the european option class wihich takes in data members and compute price and greeks of the option
//
// author: amandeep singh gujral

#ifndef EUROPEAN_OPTION_HPP
#define EUROPEAN_OPTION_HPP

#include <string>
#include <vector>
#include <any>

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
            double DeltaCall(double r, double K, double T, double sig, double b, double S) const; // delta of call option                                                       // delta of call option
            double DeltaPut(double r, double K, double T, double sig, double b, double S) const;  // delta of put option                                     // delta ofput option

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

            vector<double> GetParams() const override;                  // get a vectors of data members
            void SetParams(const any name, const double value) override; // set the value of the data member
            void SetParams(vector<double> &data);                       // set the values of the data members

            double Price() const;                                                 // compute price of the option
            vector<double> Price(const vector<vector<double>> &optionData) const; // takes input as vector to compute price of the option
            double Delta() const;                                                 // compute delta of the option
            double Gamma() const;                                                 // compute gamma of the option

            bool Parity(const double callPrice, const double putPrice, const double tolerance = 0.00001) const; // check parity for given the given K, S & T
            double Parity(const double price) const;                                                            // compute call(or put) price for a given put(or call) price

            void toggle();                  // change the type of the option
            void toggle(const string type); // specify the type of the option
        };
    }
}

#endif