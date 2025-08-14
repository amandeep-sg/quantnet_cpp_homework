// Array.hpp
// program to declare an array class which helps to create, operate upon and destroys array on heap
//
// author: amandeep singh gujral

#ifndef Array_hpp
#define Array_hpp

#include "Point.hpp"

class Array
{
private:
    Point *arr;
    int size;

public:
    Array();              // default constructor
    Array(int size);      // overload constructor to initialize with size
    Array(Array &source); // copy constructor

    ~Array(); // destructor

    Array &operator=(Array &soruce); // assignment operator overload to copy the array

    int Size();                               // get the size of the array
    Point &GetElement(const int index) const; // get element at an index from the array

    void SetElement(const int index, const Point &element); // set the element at the given index in an array

    Point &operator[](const int index);             // operator[] for accessing elements of array instance created without const
    const Point &operator[](const int index) const; // operator[] for accessing elements of array instance created with const
};

#endif