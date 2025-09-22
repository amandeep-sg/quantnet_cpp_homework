// MatrixPricer.hpp
// declare a matrix pricer class which takes in the input matrix and returns vector or matrx of option prices
//
// author: amandeep singh gujral

#ifndef MATRIX_PRICER_HPP
#define MATRIX_PRICER_HPP

#include <vector>

#include "Enum.hpp"

using namespace std;

namespace INSTRUMENT
{
    namespace SIMULATOR
    {
        template <typename T>
        class MatrixPricer
        {
        private:
            void Mesher(const Param &name); // creates a 2d mesh for simulation

        private:
            // data members
            T option;  // option instance
            double start; // starting point for the simulator
            double end;   // end point for the simulator
            int interval;
            vector<vector<double>> mesh; // 2d mesh

        public:
            // constructors and member functions
            MatrixPricer();                                                                    // default constructor
            MatrixPricer(const T &option, const int start, const int end, const int interval); // instantiates class with initial parameter as option ex. EuropeanOption, AmericanOption, etc.
            MatrixPricer(const MatrixPricer<T> &source);                                       // copy constructor
            ~MatrixPricer();                                                                   // destructor

            MatrixPricer &operator=(const MatrixPricer &source); // assignment operator

            vector<double> Simulate(const Param &name);              // run simulator by varing one parameter
            vector<vector<double>> Simulate(const Param (&name)[2]); // run simulator by varying two parameters
        };
    }
}

#ifndef MATRIX_PRICER_CPP
#include "MatrixPricer.cpp"
#endif


#endif