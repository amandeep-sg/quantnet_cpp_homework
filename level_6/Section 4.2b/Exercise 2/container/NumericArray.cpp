// NumericArray.cpp
// program to define constructor, destructor, operator overloads, data members and function memebers
// of class NumericArray derived from base class Array
//
// autor: amandeep

#ifndef NumericArray_cpp
#define NumericArray_cpp

#include <iostream>
#include "NumericArray.hpp"
#include "Array.hpp"
#include "SizeException.hpp"

using namespace std;
using namespace ADSINGH::EXCEPTION;

namespace ADSINGH
{
    namespace CONTAINER
    {
        template <typename T>
        NumericArray<T>::NumericArray() : Array<T>() { cout << "default numeric array initiated array of size " << this->Size() << endl; };

        template <typename T>
        NumericArray<T>::NumericArray(const unsigned int size) : Array<T>(size){};

        template <typename T>
        NumericArray<T>::NumericArray(const NumericArray<T> &source) : Array<T>(source){};

        template <typename T>
        NumericArray<T>::~NumericArray(){};

        template <typename T>
        NumericArray<T> &NumericArray<T>::operator=(NumericArray<T> &source)
        {
            if (this == &source)
            {
                return *this;
            }
            else
            {
                Array<T>::operator=(source);
            }
            return *this;
        }

        template <typename T>
        NumericArray<T> &NumericArray<T>::operator+(const NumericArray &source)
        {
            if (this->Size() != source.Size())
            {
                throw SizeException(this->Size(), source.Size());
            }
            else
            {
                for (int i = 0; i < this->Size(); i++)
                {
                    this->SetElement(i, this->GetElement(i) + source[i]);
                }
            }
            return *this;
        }

        template <typename T>
        NumericArray<T> &NumericArray<T>::operator*(const int factor)
        {
            for (int i = 0; i < this->Size(); i++)
            {
                this->arr[i] *= factor;
            }

            return *this;
        }
    }
}

#endif
