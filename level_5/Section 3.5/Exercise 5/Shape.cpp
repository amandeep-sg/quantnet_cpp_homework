// Shape.cpp
// program to define the constructor, destructor, getter and setter of Shape class
//
// author: amandeep singh gujral

#include <sstream>
#include <stdlib.h>
#include <iostream>

#include "Shape.hpp"

using namespace std;

namespace ADSINGH
{
    namespace CAD
    {
        Shape::Shape() : id(rand()) {};                       // default constructor, rand is used to assign value to id
        Shape::Shape(const Shape &source) : id(source.id) {}; // copy constructor

        Shape &Shape::operator=(const Shape &source) // operator= overload
        {
            id = source.id; // assign id of source to this
            return *this;
        }

        const int Shape::ID() const // get ID
        {
            return id;
        }

        string Shape::ToString() const // return id in string ex."ID: 123"
        {
            stringstream ss;
            ss << "ID: " << id;
            return ss.str();
        }

        const void Shape::Print() const
        {
            cout <<ToString()<< endl;
        }

        Shape::~Shape() 
        {
            cout <<"Shape of "<<ToString() <<" destroyed!"<< endl;
        };
    }
}