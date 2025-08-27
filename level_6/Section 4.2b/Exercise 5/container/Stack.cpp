// Stack.cpp
//  program to define the constructor, destructor, data memeber and memeber function of Stack class
//
// author: amandeep singh gujral

#ifndef Stack_cpp
#define Stack_cpp

#include <iostream>
#include <sstream>

#include "Stack.hpp"

#include "../exception/ArrayException.hpp"
#include "../exception/StackEmptyException.hpp"
#include "../exception/StackFullException.hpp"

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
            try
            {
                arr.SetElement(curr_index, source);
                curr_index++;
            }
            catch (ArrayException &ex) // catch OutOfBoundsException of class Array
            {
                throw StackFullException();
            }
            catch (...)
            {
                throw;
            }
        }

        template <typename T> // pop elements from the end of the stack and return to the client
        T &Stack<T>::Pop()
        {
            try
            {
                curr_index--;
                return arr[curr_index];
            }
            catch (ArrayException &ex) // catch OutOfBoundsException of class Array
            {
                curr_index = 0; // set current index = 0
                throw StackEmptyException();
            }
            catch (...)
            {
                throw;
            }
        }

        template <typename T> // get the value of the curr_index data memeber
        int Stack<T>::c_index() const
        {
            return curr_index;
        }

        template <typename T> // print all the elements of the stack
        string Stack<T>::Print() const
        {
            return arr.Print();
        }
    }
}

#endif