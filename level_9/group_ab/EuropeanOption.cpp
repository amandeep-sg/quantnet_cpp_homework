// EuropeanOption.cpp
// define the constructor and member functions to compute the price and geeks of the options
//
// author: amandeep singh gujral

#include <string>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <any>

#include <boost/math/distributions/normal.hpp>

#include "EuropeanOption.hpp"

using namespace std;

namespace INSTRUMENT
{
    namespace OPTION
    {
        // private member functions

        void EuropeanOption::init()
        {
            // Default values
            r = 0.03;
            sig = 0.2;
            K = 110.0;
            T = 0.5;
            S = 100.0;
            b = r;            // black-scholes stock option model
            optionType = "C"; // European Call Option default type
        }

        void EuropeanOption::copy(const EuropeanOption &source)
        {
            r = source.r;
            K = source.K;
            T = source.T;
            sig = source.sig;
            b = source.b;
            S = source.S;
            optionType = source.optionType;
        }

        double EuropeanOption::n(double x) const
        {
            boost::math::normal_distribution<> dist(0.0, 1.0);
            return boost::math::pdf(dist, x);
        }

        double EuropeanOption::N(double x) const
        {
            boost::math::normal_distribution<> dist(0.0, 1.0);
            return boost::math::cdf(dist, x);
        }

        double EuropeanOption::CallPrice(double r, double K, double T, double sig, double b, double S) const
        {
            double d1 = (log(S / K) + (b + (sig * sig) * .5) * T) / (sig * sqrt(T));
            double d2 = d1 - (sig * sqrt(T));

            return (S * exp((b - r) * T) * N(d1)) - (K * exp(-r * T) * N(d2));
        }

        double EuropeanOption::PutPrice(double r, double K, double T, double sig, double b, double S) const
        {
            double d1 = (log(S / K) + (b + (sig * sig) * .5) * T) / (sig * sqrt(T));
            double d2 = d1 - (sig * sqrt(T));

            return (K * exp(-r * T) * N(-d2)) - (S * exp((b - r) * T) * N(-d1));
        }

        double EuropeanOption::DeltaCall(double r, double K, double T, double sig, double b, double S) const
        {
            double d1 = (log(S / K) + (b + (sig * sig) * .5) * T) / (sig * sqrt(T));
            return (exp((b - r) * T) * N(d1));
        }

        double EuropeanOption::DeltaPut(double r, double K, double T, double sig, double b, double S) const
        {
            double d1 = (log(S / K) + (b + (sig * sig) * .5) * T) / (sig * sqrt(T));
            return (exp((b - r) * T) * (N(d1) - 1.0));
        }

        double EuropeanOption::Gamma(double r, double K, double T, double sig, double b, double S) const
        {
            double d1 = (log(S / K) + (b + (sig * sig) * .5) * T) / (sig * sqrt(T));
            return (n(d1) * exp((b - r) * T)) / (S * sig * sqrt(T));
        }

        // constructors
        EuropeanOption::EuropeanOption() : Option()
        {
            init();
        }

        EuropeanOption::EuropeanOption(const double r, const double K, const double T, const double sig, const double b, const double S, const string optionType) : Option()
        {
            this->r = r;
            this->K = K;
            this->T = T;
            this->sig = sig;
            this->b = b;
            this->S = S;
            toggle(optionType);
        }

        EuropeanOption::EuropeanOption(const EuropeanOption &source) : Option(source)
        {
            copy(source);
        }

        EuropeanOption::~EuropeanOption() {};

        // operator overload
        EuropeanOption &EuropeanOption::operator=(const EuropeanOption &source)
        {
            if (this == &source)
                return *this;

            copy(source);
            return *this;
        }

        // member functions
        vector<double> EuropeanOption::Params() const
        {
            return vector<double>{r, K, T, sig, b, S};
        }

        void EuropeanOption::Params(const Param name, const double value)
        {
            switch (name)
            {
            case Param::RETURN:
                this->r = value;
                break;
            case Param::STRIKE:
                this->K = value;
                break;
            case Param::MATURITY:
                this->T = value;
                break;
            case Param::SIGMA:
                this->sig = value;
                break;
            case Param::COC:
                this->b = value;
                break;
            case Param::SPOT:
                this->S = value;
                break;
            default:
                throw invalid_argument("input error: not a valid european option param!");
            };
        }

        void EuropeanOption::Params(vector<double> &data)
        {
            this->r = data[0];
            this->K = data[1];
            this->T = data[2];
            this->sig = data[3];
            this->b = data[4];
            this->S = data[5];
        }

        double EuropeanOption::Price() const
        {
            if (optionType == "C")
            {
                return CallPrice(r, K, T, sig, b, S);
            }
            else
            {
                return PutPrice(r, K, T, sig, b, S);
            }
        }

        vector<double> EuropeanOption::Price(const vector<vector<double>> &optionDataMatrix) const
        {
            vector<double> result;

            for (const vector<double> &row : optionDataMatrix)
            {
                if (optionType == "C")
                {
                    result.push_back(CallPrice(row[0], row[1], row[2], row[3], row[4], row[5]));
                }
                else
                {
                    result.push_back(PutPrice(row[0], row[1], row[2], row[3], row[4], row[5]));
                }
            }
            return result;
        }

        double EuropeanOption::Delta() const
        {
            if (optionType == "C")
            {
                return DeltaCall(r, K, T, sig, b, S);
            }
            else
            {
                return DeltaPut(r, K, T, sig, b, S);
            }
        }

        double EuropeanOption::Delta(const double h) const
        {
            double result;
            if (optionType == "C")
            {
                return (CallPrice(r, K, T, sig, b, S + h) - CallPrice(r, K, T, sig, b, S - h)) / (2 * h);
            }
            else
            {
                return (PutPrice(r, K, T, sig, b, S + h) - PutPrice(r, K, T, sig, b, S - h)) / (2 * h);
            }
        }

        vector<double> EuropeanOption::Delta(const vector<vector<double>> &optionDataMatrix) const
        {
            vector<double> result;
            for (const vector<double> row : optionDataMatrix)
            {
                if (optionType == "C")
                {
                    result.push_back(DeltaCall(row[0], row[1], row[2], row[3], row[4], row[5]));
                }
                else
                {
                    result.push_back(DeltaPut(row[0], row[1], row[2], row[3], row[4], row[5]));
                }
            }
            return result;
        }

        double EuropeanOption::Gamma() const
        {
            return Gamma(r, K, T, sig, b, S);
        }

        double EuropeanOption::Gamma(const double h) const
        {
            return (CallPrice(r, K, T, sig, b, S + h) + CallPrice(r, K, T, sig, b, S - h) - 2 * CallPrice(r, K, T, sig, b, S)) / (h * h);
        }

        vector<double> EuropeanOption::Gamma(const vector<vector<double>> &optionDataMatrix) const
        {
            vector<double> result;
            for (const vector<double> row : optionDataMatrix)
            {
                result.push_back(Gamma(row[0], row[1], row[2], row[3], row[4], row[5]));
            }
            return result;
        }

        bool EuropeanOption::Parity(const double callPrice, const double putPrice, const double tolerance) const
        {
            bool result = 0;
            if (((callPrice + K * exp(-r * T)) - (putPrice + S)) < tolerance)
            {
                result = 1;
            }
            return result;
        }

        double EuropeanOption::Parity(const double price) const
        {
            if (optionType == "C")
            {
                return (price + S - (K * exp(-r * T))); // return call price
            }
            else
            {
                return (price + (K * exp(-r * T)) - S); // return put price
            }
        }

        void EuropeanOption::toggle()
        {
            if (optionType == "C")
            {
                optionType = "P";
            }
            else
            {
                optionType = "C";
            }
        }

        void EuropeanOption::toggle(const string type)
        {
            if (type == "C" || type == "c")
            {
                optionType = "C";
            }
            else if (type == "P" || type == "p")
            {
                optionType = "P";
            }
            else
            {
                throw invalid_argument("error: invalid option type value!");
            }
        }
    }
}