// NumericArray.hpp
// program to declare the constructor, destructor, data members and function members
// of class NumericArray derived from class Array
//
// author: amandeepsingh gujral

#ifndef NumericArray_hpp
#define NumericArray_hpp

#include "Array.hpp"

using namespace std;
using namespace ADSINGH::CONTAINER;

namespace ADSINGH
{
    namespace CONTAINER
    {
        template <typename T>
        class NumericArray : public Array<T>
        {
        public:
            NumericArray();                              // default constructor
            NumericArray(const unsigned int size);       // constructor initialises array with size passed in argumnets
            NumericArray(const NumericArray<T> &source); // copy constructor
            ~NumericArray();                             // desstructor

            NumericArray<T> &operator=(NumericArray<T> &source);  // assignment operator
            NumericArray<T> &operator+(const NumericArray<T> &sorurce); // operator+ overload to add elements of two arrays
            NumericArray<T> &operator*(const int factor);               // scale the elements of the array by factor

            T DotProduct(const NumericArray<T> &source); // function to calculate the dot product of two numeric arrays
        };
    }
}

#ifndef NumericArray_cpp
#include "NumericArray.cpp"
#endif

#endif