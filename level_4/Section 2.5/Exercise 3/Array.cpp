// Array.cpp
// program to define the Array class i.e. constructors, member functions
//
// author: amandeep singh gujral

#include <iostream>

#include "Array.hpp"
#include "Point.hpp"

using namespace std;

Array::Array() : size(10) // default constructor initialise array of size 10
{
    arr = new Point[size];
    cout << "default constructor call: array initialise of size 10" << endl;
}

Array::Array(int size) : size(size)
{
    arr = new Point[size];
    cout << "constructor call: array initialised of size " << size << endl;
}

Array::Array(Array &source)
{
    size = source.size;
    arr = new Point[size];
    if (arr == nullptr)
    {
        cout << "error: insufficient memory!" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = source.arr[i];
        }
    }
    cout << "constructor called: array of size " << size << " copied!" << endl;
}

Array::~Array()
{
    delete[] arr;
    cout << "deleted array of size " << size << endl;
}

Array &Array::operator=(Array &source)
{
    if (this == &source)
    {
        return *this;
    }
    else
    {
        delete[] arr;
        size = source.size;
        arr = new Point[size];

        if (arr == nullptr)
        {
            cout << "error: insufficient memory!" << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] = source.arr[i];
            }
        }
    }
    return *this;
}

int Array::Size()
{
    return size;
}

Point &Array::GetElement(int index) const
{
    if (index > 0 || index < size)
    {
        return arr[index];
    }
    return arr[0];
}

void Array::SetElement(const int index, const Point &element)
{
    if (index > 0 || index < size)
    {
        arr[index] = element;
    }
}

const Point &Array::operator[](int index) const
{
    cout << "member function with const is called" << endl;
    return GetElement(index);
}

Point &Array::operator[](int index)
{
    cout << "member function is called!" << endl;
    return GetElement(index);
}
