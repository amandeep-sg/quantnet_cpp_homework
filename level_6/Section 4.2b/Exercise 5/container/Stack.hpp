// Stack.hpp
//  declare the constructor, destructor, data member and memeber function fo stack class
//  stack class is not derived from Array class, instead uses Array as its data member
//
// author: amandeep singh gujral

#ifndef Stack_hpp
#define Stack_hpp

#include<sstream>

#include "Array.hpp"

namespace ADSINGH
{
    namespace CONTAINER
    {
        template <typename T>
        class Stack
        {
        private:
            Array<T> arr; // Array data member, an example of composition
            int curr_index; // current index of the stack

        public:
            Stack(); // default constructor
            Stack(const unsigned int size); // constructor to instantiate the stack of size defined by client
            Stack(const Stack &source); // copy constructor

            ~Stack(); // destructor

            Stack &operator=(const Stack &source); // assigment operator overload

            void Push(const T &source); // push elements to the end of the stack
            T &Pop(); // pop out elements from the end of the stack and return to the client
            int c_index() const; // get the current index of the stack
            string Print() const; // print the elements of the stack
        };
    }
}

#ifndef Stack_cpp
#include "Stack.cpp"
#endif

#endif