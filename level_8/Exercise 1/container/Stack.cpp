// Stack.cpp
//  program to define the constructor, destructor, data memeber and memeber function of Stack class
// size of stack is a template argument
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

        template <typename T, int size> // default constctor
        Stack<T, size>::Stack() : curr_index(0), arr(size){};

        template <typename T, int size> // copy constructor
        Stack<T, size>::Stack(const Stack &source) : arr(source.arr), curr_index(source.curr_index){};

        template <typename T, int size> // destructor
        Stack<T, size>::~Stack(){};

        template <typename T, int size> // assignment operator overload
        Stack<T, size> &Stack<T, size>::operator=(const Stack &source)
        {
            if (this == &source)
            {
                return *this;
            }
            arr = source.arr;
            curr_index = source.curr_index;
            return *this;
        }

        template <typename T, int size> // push elements to the end of the client
        void Stack<T, size>::Push(const T &source)
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

        template <typename T, int size> // pop elements from the end of the stack and return to the client
        T &Stack<T, size>::Pop()
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

        template <typename T, int size> // get the value of the curr_index data memeber
        int Stack<T, size>::c_index()
        {
            return curr_index;
        }

        template <typename T, int size> // print all the elements of the stack
        string Stack<T, size>::Print()
        {
            return arr.Print();
        }
    }
}

#endif