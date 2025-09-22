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
            vector<double> original = option.GetParams();

            mesh.clear();
            double step = (end - start) / double(interval);

            for (double i = start; i <= end; i += step)
            {
                option.SetParams(name, i);
                mesh.push_back(option.GetParams());
            }
            option.SetParams(original);
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

        template <typename T>
        vector<double> MatrixPricer<T>::Simulate(const Param &name)
        {
            Mesher(name);
            return option.Price(mesh);
        };

        template <typename T>
        vector<vector<double>> MatrixPricer<T>::Simulate(const Param (&name)[2])
        {
            vector<double> original = option.GetParams();
            vector<vector<double>> result;
            mesh.clear();
            double step = (end - start) / double(interval);
            for (double i = start; i <= end; i += step)
            {
                option.SetParams(name[0], i);
                Mesher(name[1]);
                result.push_back(option.Price(mesh));
            }
            option.SetParams(original);
            return result;
        }
    }
}

#endif