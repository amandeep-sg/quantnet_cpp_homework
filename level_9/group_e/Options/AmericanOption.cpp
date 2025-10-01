// AmericanOption.cpp
// define the constructor and member functions to compute the price and geeks of the options
//
// author: amandeep singh gujral

#ifndef AMERICAN_OPTION_CPP
#define AMERICAN_OPTION_CPP

#include <vector>
#include <iostream>
#include <boost/math/distributions/normal.hpp>

#include "Enum.hpp"
#include "AmericanOption.hpp"

using namespace std;

namespace INSTRUMENT
{
    namespace OPTION
    {
        // private member functions
        void AmericanOption::init()
        {
            // Default values
            r = 0.03;
            sig = 0.2;
            K = 110.0;
            S = 100.0;
            b = r;            // black-scholes stock option model
            optionType = "C"; // European Call Option default type
        }

        void AmericanOption::copy(const AmericanOption &source)
        {
            r = source.r;
            K = source.K;
            sig = source.sig;
            b = source.b;
            S = source.S;
            optionType = source.optionType;
        }

        double AmericanOption::CallPrice(double r, double K, double sig, double b, double S) const
        {
            double y1 = 0.5 - b / (sig * sig) + sqrt(pow((b / (sig * sig) - 0.5), 2) + 2 * r / (sig * sig));
            return K * pow(((y1 - 1) * S / (y1 * K)), y1) / (y1 - 1);
        }

        double AmericanOption::PutPrice(double r, double K, double sig, double b, double S) const
        {
            double y2 = 0.5 - b / (sig * sig) - sqrt(pow((b / (sig * sig) - 0.5), 2) + 2 * r / (sig * sig));
            return K * pow(((y2 - 1) * S / (y2 * K)), y2) / (1 - y2);
        }

        // constructors & destructor
        AmericanOption::AmericanOption()
        {
            init();
        }

        AmericanOption::AmericanOption(const double r, const double K, const double sig, const double b, const double S, const string optionType)
        {
            this->r = r;
            this->K = K;
            this->sig = sig;
            this->b = b;
            this->S = S;
            toggle(optionType);
        }

        AmericanOption::AmericanOption(const AmericanOption &source)
        {
            copy(source);
        }

        AmericanOption::~AmericanOption() {};

        // operator overloading
        AmericanOption &AmericanOption::operator=(const AmericanOption &source)
        {
            if (this == &source)
                return *this;

            copy(source);
            return *this;
        }

        // getter
        vector<double> AmericanOption::Params() const
        {
            return vector<double>{r, K, sig, b, S};
        }

        // setter
        void AmericanOption::Params(const Param name, const double value)
        {
            switch (name) // set param value based on the enum
            {
            case Param::RETURN:
                this->r = value;
                break;
            case Param::STRIKE:
                this->K = value;
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
                throw invalid_argument("input error: not a valid american option param!");
            };
        }

        void AmericanOption::Params(vector<double> &data)
        {
            if (data.size() != 5) // check if the vector contains all the parameters
                throw invalid_argument("input error: invalid vector of parameters!");
            this->r = data[0];
            this->K = data[1];
            this->sig = data[2];
            this->b = data[3];
            this->S = data[4];
        }

        double AmericanOption::Price() const
        {
            if (optionType == "C") // check for option type
            {
                return CallPrice(r, K, sig, b, S);
            }
            else
            {
                return PutPrice(r, K, sig, b, S);
            }
        }

        vector<double> AmericanOption::Price(const vector<vector<double>> &optionDataMatrix) const
        {
            vector<double> result;

            for (const vector<double> &row : optionDataMatrix) //compute for each row in the matrix
            {
                if (optionType == "C")
                {
                    result.push_back(CallPrice(row[0], row[1], row[2], row[3], row[4]));
                }
                else
                {
                    result.push_back(PutPrice(row[0], row[1], row[2], row[3], row[4]));
                }
            }
            return result;
        }

        void AmericanOption::toggle() //implicit toggle
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

        void AmericanOption::toggle(const string type) // expicit toggle
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

#endif