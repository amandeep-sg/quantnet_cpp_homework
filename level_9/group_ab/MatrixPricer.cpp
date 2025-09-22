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
        template <typename T>
        void MatrixPricer<T>::Mesher(const Param &name)
        {
            vector<double> original = option.Params();

            mesh.clear();
            double step = (end - start) / double(interval);

            for (double i = start; i <= end; i += step)
            {
                option.Params(name, i);
                mesh.push_back(option.Params());
            }
            option.Params(original);
        };

        template <typename T>
        MatrixPricer<T>::MatrixPricer(){};

        template <typename T>
        MatrixPricer<T>::MatrixPricer(const T &opt, const int s, const int e, const int size) : option(opt), start(s), end(e), interval(size){};

        template <typename T>
        MatrixPricer<T>::MatrixPricer(const MatrixPricer &source) : option(source.option){};

        template <typename T>
        MatrixPricer<T>::~MatrixPricer(){};

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
            Mesher(name);
            return option.Price(mesh);
        };

        template <typename T>
        vector<vector<double>> MatrixPricer<T>::SimulatePrice(const Param (&name)[2])
        {
            vector<double> original = option.Params();
            vector<vector<double>> result;
            mesh.clear();
            double step = (end - start) / double(interval);
            for (double i = start; i <= end; i += step)
            {
                option.Params(name[0], i);
                Mesher(name[1]);
                result.push_back(option.Price(mesh));
            }
            option.Params(original);
            return result;
        }

        template <typename T>
        vector<double> MatrixPricer<T>::SimulateDelta(const Param &name)
        {
            Mesher(name);
            return option.Delta(mesh);
        };

        template <typename T>
        vector<vector<double>> MatrixPricer<T>::SimulateDelta(const Param (&name)[2])
        {
            vector<double> original = option.Params();
            vector<vector<double>> result;
            mesh.clear();
            double step = (end - start) / double(interval);
            for (double i = start; i <= end; i += step)
            {
                option.Params(name[0], i);
                Mesher(name[1]);
                result.push_back(option.Delta(mesh));
            }
            option.Params(original);
            return result;
        }

        template <typename T>
        vector<double> MatrixPricer<T>::SimulateGamma(const Param &name)
        {
            Mesher(name);
            return option.Gamma(mesh);
        };

        template <typename T>
        vector<vector<double>> MatrixPricer<T>::SimulateGamma(const Param (&name)[2])
        {
            vector<double> original = option.Params();
            vector<vector<double>> result;
            mesh.clear();
            double step = (end - start) / double(interval);
            for (double i = start; i <= end; i += step)
            {
                option.Params(name[0], i);
                Mesher(name[1]);
                result.push_back(option.Gamma(mesh));
            }
            option.Params(original);
            return result;
        }
    }
}

#endif