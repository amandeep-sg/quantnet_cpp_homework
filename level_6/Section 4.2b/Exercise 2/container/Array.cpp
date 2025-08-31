// Array.cpp
// program to define the Array class i.e. constructors, member functions
//
// author: amandeep singh gujral

#ifndef Array_cpp
#define Array_cpp

#include <iostream>
#include <sstream>

#include "Array.hpp"
#include "../exception/OutOfBoundsException.hpp"

using namespace std;
using namespace ADSINGH::EXCEPTION;

namespace ADSINGH
{
    namespace CONTAINER
    {
        template <typename T>
        Array<T>::Array() : size(default_size) // default constructor initialise array of size 5
        {
            arr = new T[size];
            // cout << "default constructor called: array initialise of size 5" << endl;
        }

        template <typename T>
        Array<T>::Array(const unsigned int size) : size(size) // constructor initialises the array of size defines by client
        {
            arr = new T[size];
            // cout << "constructor called: array initialised of size " << size << endl;
        }

        template <typename T>
        Array<T>::Array(const Array &source) // copy constructor
        {
            size = source.size;
            arr = new T[size];
            if (arr == nullptr) // check if the memory is assigned in the heap
            {
                cout << "error: insufficient memory!" << endl;
            }
            else
            {
                for (int i = 0; i < size; i++) // for loop to copy each element of the source array to this.
                {
                    arr[i] = source.arr[i];
                }
            }
            // cout << "constructor called: array of size " << size << " copied!" << endl;
        }

        template <typename T>
        Array<T>::~Array() // destructor to delete the array when out of scope
        {
            delete[] arr;
            // cout << "deleted array of size " << size << endl;
        }

        template <typename T>
        Array<T> &Array<T>::operator=(const Array<T> &source) // assigment operator to copy element of one array to another
        {
            if (this == &source) // check if the source array == *this to avoid deletion of the elements
            {
                return *this;
            }
            else
            {
                delete[] arr;       // delete the element of the this array;
                size = source.size; // set the size of this array equal to source;
                arr = new T[size];

                if (arr == nullptr) // check if the memory is assigned in the heap
                {
                    cout << "error: insufficient memory!" << endl;
                }
                else
                {
                    for (int i = 0; i < size; i++) // for loop to copy each element of the source array to this.
                    {
                        arr[i] = source.arr[i];
                    }
                }
            }
            return *this;
        }

        template <typename T>
        int Array<T>::Size() const // get the size of the array instance
        {
            return size;
        }

        template <typename T>
        T &Array<T>::GetElement(int index) const // get the element of the array instance based on index argument
        {
            if (index < 0 || index >= size)
            {
                throw OutOfBoundsException(index); // throw -1 if index is out of range
            }
            return arr[index];
        }

        template <typename T>
        void Array<T>::SetElement(const int index, const T &element) // set the element at the index in an array
        {
            if (index < 0 || index >= size)
            {
                throw OutOfBoundsException(index); // through -1 if index is out of range
            }
            arr[index] = element;
        }

        template <typename T>
        const T &Array<T>::operator[](int index) const // overload operator[] to get element of an array instance created with const
        {
            return GetElement(index);
        }

        template <typename T>
        T &Array<T>::operator[](int index) // overload operator[] to get element of an array instance created without const
        {

            return GetElement(index);
        }

        template <typename T>
        unsigned int Array<T>::default_size = 5; // initialise static variable

        template <typename T>
        unsigned int Array<T>::DefaultSize()
        {
            return default_size;
        }

        template <typename T>
        void Array<T>::DefaultSize(const unsigned int size)
        {
            default_size = size;
        }

        template <typename T>
        const string Array<T>::Print() const
        {
            stringstream ss;
            for (int i = 0; i < size; i++)
            {
                ss << arr[i];
                if (i < size - 1)
                {
                    ss << ", ";
                }
            }
            return ss.str();
        }
    }
}

#endif