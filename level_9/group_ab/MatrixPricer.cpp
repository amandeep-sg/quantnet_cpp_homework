// MatrixPricer.cpp
//  define the constructor, operator and member functions of the matrix pricer simulator
//
// author: amandeep singh gujral

#ifndef MATRIX_PRICER_CPP
#define MATRIX_PRICER_CPP

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "MatrixPricer.hpp"
#include "Enum.hpp"

using namespace std;

namespace INSTRUMENT
{
    namespace SIMULATOR
    {
        // private member functions
        template <typename T>
        void MatrixPricer<T>::Mesher(const Param &name)
        {
            vector<double> original = option.Params();

            mesh.clear();                                   // clean the matrix
            double step = (end - start) / double(interval); // compute the step size

            for (double i = start; i <= end; i += step)
            {
                option.Params(name, i);          // set the value of the option parameter based on the enum
                mesh.push_back(option.Params()); // get the option parameter vector and push it to matrix
            }
            option.Params(original); // restore the option parameter to original values
        };

        // constructors & destructor
        template <typename T>
        MatrixPricer<T>::MatrixPricer(){};

        template <typename T>
        MatrixPricer<T>::MatrixPricer(const T &opt, const int s, const int e, const int size) : option(opt), start(s), end(e), interval(size){};

        template <typename T>
        MatrixPricer<T>::MatrixPricer(const MatrixPricer &source) : option(source.option), start(source.start), end(source.end), interval(source.interval){};

        template <typename T>
        MatrixPricer<T>::~MatrixPricer(){};

        // opterator overloading
        template <typename T>
        MatrixPricer<T> &MatrixPricer<T>::operator=(const MatrixPricer &source)
        {
            if (this == &source)
                return *this;

            option = source.option;
            return *this;
        };

        // getters
        template <typename T>
        T MatrixPricer<T>::Option() const
        {
            return option;
        }

        template <typename T>
        int MatrixPricer<T>::Start() const
        {
            return start;
        }

        template <typename T>
        int MatrixPricer<T>::End() const
        {
            return end;
        }

        template <typename T>
        int MatrixPricer<T>::Interval() const
        {
            return interval;
        }

        // setters
        template <typename T>
        void MatrixPricer<T>::Option(const T &option)
        {
            this->option = option;
        }

        template <typename T>
        void MatrixPricer<T>::Start(const int value)
        {
            this->start = value;
        }

        template <typename T>
        void MatrixPricer<T>::End(const int value)
        {
            this->end = value;
        }

        template <typename T>
        void MatrixPricer<T>::Interval(const int value)
        {
            this->interval = value;
        }

        // simulate function
        template <typename T>
        vector<double> MatrixPricer<T>::SimulatePrice(const Param &name)
        {
            Mesher(name);              // prepare the option data matrix
            return option.Price(mesh); // generate the price vector by submitting option data matrix
        };

        template <typename T>
        vector<vector<double>> MatrixPricer<T>::SimulatePrice(const Param (&name)[2])
        {
            vector<double> original = option.Params(); // get original state of the option object
            vector<vector<double>> result;
            mesh.clear();
            double step = (end - start) / double(interval); // compute step size
            for (double i = start; i <= end; i += step)
            {
                option.Params(name[0], i);            // set the value of the option parameter based on the enum
                Mesher(name[1]);                      // prepare the option data matrix
                result.push_back(option.Price(mesh)); // generate the price vector by submitting option data matrix
            }
            option.Params(original); // restore the option parameter to original
            return result;
        }

        template <typename T>
        vector<double> MatrixPricer<T>::SimulateDelta(const Param &name)
        {
            Mesher(name);              // prepare the option data matrix
            return option.Delta(mesh); // generate the delta vector by submitting option data matrix using exact method
        };

        template <typename T>
        vector<double> MatrixPricer<T>::SimulateDeltaNum(const Param &name, const double h)
        {
            Mesher(name);                 // prepare the option data matrix
            return option.Delta(mesh, h); // generate the delta vector by submitting option data matrix using divide differance
        }

        template <typename T>
        vector<vector<double>> MatrixPricer<T>::SimulateDelta(const Param (&name)[2])
        {
            vector<double> original = option.Params(); // get original state of the option object
            vector<vector<double>> result;
            mesh.clear();
            double step = (end - start) / double(interval); // compute step size
            for (double i = start; i <= end; i += step)
            {
                option.Params(name[0], i);            // set the value of the option parameter based on the enum
                Mesher(name[1]);                      // prepare the option data matrix
                result.push_back(option.Delta(mesh)); // generate the delta vector by submitting option data matrix
            }
            option.Params(original); // restore the option parameter to original
            return result;
        }

        template <typename T>
        vector<double> MatrixPricer<T>::SimulateGamma(const Param &name)
        {
            Mesher(name);              // prepare option data matrix
            return option.Gamma(mesh); // generate the gamma vector by submitting option data matrix using divide differance
        };

        template <typename T>
        vector<vector<double>> MatrixPricer<T>::SimulateGamma(const Param (&name)[2])
        {
            vector<double> original = option.Params(); // get original state of the option object
            vector<vector<double>> result;
            mesh.clear();
            double step = (end - start) / double(interval); // compute step size
            for (double i = start; i <= end; i += step)
            {
                option.Params(name[0], i);            // set the value of the option parameter based on the enum
                Mesher(name[1]);                      // prepare option data matrix
                result.push_back(option.Gamma(mesh)); // generate the gamma vector by submitting option data matrix
            }
            option.Params(original); // restore the option parameter to original
            return result;
        }
    }
}

#endif