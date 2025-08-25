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
#include "../exception/SizeException.hpp"

using namespace std;
using namespace ADSINGH::EXCEPTION;

namespace ADSINGH
{
    namespace CONTAINER
    {
        template <typename T> // default constructor
        NumericArray<T>::NumericArray() : Array<T>()
        {
            cout << "default numeric array initiated array of size " << this->Size() << endl;
        };

        template <typename T> // constructor initialises the array of size defined by client
        NumericArray<T>::NumericArray(const unsigned int size) : Array<T>(size)
        {
            cout << "constructor called: numeric array initialised of size " << size << endl;
        };

        template <typename T> // copy constructor
        NumericArray<T>::NumericArray(const NumericArray<T> &source) : Array<T>(source){};

        template <typename T> // destructor
        NumericArray<T>::~NumericArray()
        {
            cout << "numeric array destructor called!" << endl;
        };

        template <typename T> //=operator overload
        NumericArray<T> &NumericArray<T>::operator=(NumericArray<T> &source)
        {
            if (this == &source) // check if the source array == *this to avoid deletion of the elements
            {
                return *this;
            }
            else
            {
                Array<T>::operator=(source); // explicitely call base class =operator overload
            }
            return *this;
        }

        template <typename T> //+operator overload
        NumericArray<T> &NumericArray<T>::operator+(const NumericArray &source)
        {
            if (this->Size() != source.Size()) // check it the size of this array and source are different
            {
                throw SizeException(this->Size(), source.Size()); // throw incompatible size exception
            }
            else
            {
                for (int i = 0; i != this->Size(); i++) // for loop to add the elements of source to this and set new values
                {
                    this->SetElement(i, this->GetElement(i) + source[i]);
                }
            }
            return *this;
        }

        template <typename T> // *operator overload
        NumericArray<T> &NumericArray<T>::operator*(const int factor)
        {
            for (int i = 0; i != this->Size(); i++) // for loop to scale each element of the array by the factor and set new values
            {
                this->SetElement(i, this->GetElement(i) * factor);
            }

            return *this;
        }

        template <typename T> // compute dot product of the array => Arr[a]*Arr[b] = a1*b1 + a2*b2 + . . . . + an*bn
        T NumericArray<T>::DotProduct(const NumericArray<T> &source)
        {
            T dot_product(0); // initalise the value

            if (this->Size() != source.Size()) // check if the sizes of this and source array are different
            {
                throw SizeException(this->Size(), source.Size()); // through size exception
            }
            else
            {
                for (int i = 0; i != this->Size(); i++) // for loop to compute the dot product
                {
                    dot_product += (this->GetElement(i) * source[i]);
                }
            }

            return dot_product;
        }
    }
}

#endif
