// Stack.cpp
//  program to define the constructor, destructor, data memeber and memeber function of Stack class
//
// author: amandeep singh gujral

#ifndef Stack_cpp
#define Stack_cpp

#include <iostream>
#include <sstream>

#include "Stack.hpp"

#include "../exception/OutOfBoundsException.hpp"

using namespace std;
namespace ADSINGH
{
    namespace CONTAINER
    {

        template <typename T> // default constructor
        Stack<T>::Stack() : curr_index(0){};

        template <typename T> // constructor to instantiate the Stack with size defined by the customer
        Stack<T>::Stack(const unsigned int size) : arr(size), curr_index(0){};

        template <typename T> // copy constructor
        Stack<T>::Stack(const Stack &source) : arr(source.arr), curr_index(source.curr_index){};

        template <typename T> // destructor
        Stack<T>::~Stack(){};

        template <typename T> // assignment operator overload
        Stack<T> &Stack<T>::operator=(const Stack &source)
        {
            if (this == &source)
            {
                return *this;
            }
            arr = source.arr;
            curr_index = source.curr_index;
            return *this;
        }

        template <typename T> // push elements to the end of the client
        void Stack<T>::Push(const T &source)
        {
            if (curr_index == arr.Size()) // check if the stack is overloaded
            {
                throw OutOfBoundsException(curr_index);
            }
            arr.SetElement(curr_index, source);
            curr_index++;
        }

        template <typename T> // pop elements from the end of the stack and return to the client
        T &Stack<T>::Pop()
        {
            if (curr_index == 0) // check if stack if fully offloaded
            {
                throw OutOfBoundsException(curr_index);
            }
            curr_index--;
            return arr[curr_index];
        }

        template <typename T> // get the value of the curr_index data memeber
        int Stack<T>::c_index()
        {
            return curr_index;
        }

        template <typename T> // print all the elements of the stack
        string Stack<T>::Print()
        {
            return arr.Print();
        }
    }
}

#endif