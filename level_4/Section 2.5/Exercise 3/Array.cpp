// Array.cpp
// program to define the Array class i.e. constructors, member functions
//
// author: amandeep singh gujral

#include <iostream>

#include "Array.hpp"
#include "Point.hpp"

using namespace std;

Array::Array() : size(5) // default constructor initialise array of size 5
{
    arr = new Point[size];
    cout << "default constructor called: array initialise of size 5" << endl;
}

Array::Array(int size) : size(size) // constructor initialises the array of size defines by client
{
    arr = new Point[size];
    cout << "constructor called: array initialised of size " << size << endl;
}

Array::Array(Array &source) // copy constructor
{
    size = source.size;
    arr = new Point[size];
    if (arr == nullptr) // check if the memory is assigned in the heap
    {
        cout << "error: insufficient memory!" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++) //for loop to copy each element of the source array to this.
        {
            arr[i] = source.arr[i]; 
        }
    }
    cout << "constructor called: array of size " << size << " copied!" << endl;
}

Array::~Array() // destructor to delete the array when out of scope
{
    delete[] arr;
    cout << "deleted array of size " << size << endl;
}

Array &Array::operator=(Array &source) // assigment operator to copy element of one array to another
{
    if (this == &source) // check if the source array == *this to avoid deletion of the elements
    {
        return *this;
    }
    else
    {
        delete[] arr; // delete the element of the this array;
        size = source.size; // set the size of this array equal to source;
        arr = new Point[size];

        if (arr == nullptr)// check if the memory is assigned in the heap
        {
            cout << "error: insufficient memory!" << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)//for loop to copy each element of the source array to this.
            {
                arr[i] = source.arr[i];
            }
        }
    }
    return *this;
}

int Array::Size() const // get the size of the array instance
{
    return size;
}

Point &Array::GetElement(int index) const // get the element of the array instance based on index argument
{
    if (index >= 0 || index < size)
    {
        return arr[index];
    }
    return arr[0];
}

void Array::SetElement(const int index, const Point &element) // set the Point element at the index in an array
{
    if (index >= 0 || index < size)
    {
        arr[index] = element;
    }
}

const Point &Array::operator[](int index) const // overload operator[] to get element of an array instance created with const
{
    cout <<endl<<"note: member function with const is called" << endl;
    return GetElement(index);
}

Point &Array::operator[](int index) // overload operator[] to get element of an array instance created without const
{
    cout <<endl<<"note: member function is called!" << endl;
    return GetElement(index);
}
