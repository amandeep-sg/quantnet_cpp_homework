// IsSmaller.cpp
// define the IsSmaller functor to be used in algorithms like count_if(), etc.
//
// author: amandeep singh gujral

#ifndef IsSmaller_cpp
#define IsSmaller_cpp

#include "IsSmaller.hpp"
namespace ADSINGH
{
    namespace FUNCTION_OBJECT
    {
        template <typename T>
        IsSmaller<T>::IsSmaller() : threshold(0.00){}; // default constructor

        template <typename T>
        IsSmaller<T>::IsSmaller(const T threshold_value) : threshold(threshold_value){};

        template <typename T>
        IsSmaller<T>::IsSmaller(const IsSmaller<T> &source) : threshold(source.threshold){};

        template <typename T>
        IsSmaller<T>::~IsSmaller(){};

        template <typename T>
        IsSmaller<T> &IsSmaller<T>::operator=(const IsSmaller<T> &source)
        {
            threshold = source.threshold;
            return *this;
        }

        template <typename T>
        bool IsSmaller<T>::operator()(const T &value) const
        {
            return threshold > value;
        }

    }
}

#endif
