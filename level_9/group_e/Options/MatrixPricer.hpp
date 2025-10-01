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
            T option;     // option instance
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

            // getters
            T Option() const;     // returns the instance of the option being used for simulation
            int Start() const;    // returns the start point
            int End() const;      // returns the end point
            int Interval() const; // returns the interval

            // setters
            void Option(const T &option);   // set the option instance to be used for simulation
            void Start(const int value);    // set the start point
            void End(const int value);      // set the end point
            void Interval(const int value); // set the interval

            // simulate attributes
            vector<double> SimulatePrice(const Param &name);                          // run price simulator by varing one parameter
            vector<vector<double>> SimulatePrice(const Param (&name)[2]);             // run price simulator by varying two parameters
            vector<double> SimulateDelta(const Param &name);                          // run delta simulator by varing one parameter
            vector<double> SimulateDeltaNum(const Param &name, const double divisor); // run delta simulator by varing one parameter using divided differance method
            vector<vector<double>> SimulateDelta(const Param (&name)[2]);             // run delta simulator by varying two parameters
            vector<double> SimulateGamma(const Param &name);                          // run delta simulator by varing one parameter
            vector<vector<double>> SimulateGamma(const Param (&name)[2]);             // run delta simulator by varying two parameters
        };
    }
}

#ifndef MATRIX_PRICER_CPP
#include "MatrixPricer.cpp"
#endif

#endif