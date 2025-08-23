// Array.hpp
// program to declare an array template class which helps to create, operate upon and destroys array on heap
//
// author: amandeep singh gujral

#ifndef Array_hpp
#define Array_hpp

namespace ADSINGH
{
    namespace CONTAINER
    {
        template <typename T>
        class Array
        {
        private:
            T *arr;
            int size;
            static unsigned int default_size;

        public:
            Array();                 // default constructor
            Array(const unsigned int size);         // overload constructor to initialize with size
            Array(Array<T> &source); // copy constructor

            ~Array(); // destructor

            Array<T> &operator=(Array<T> &soruce); // assignment operator overload to copy the array

            int Size() const;               // get the size of the array
            T &GetElement(const int index) const; // get element at an index from the array

            void SetElement(const int index, const T &element); // set the element at the given index in an array

            T &operator[](const int index);             // operator[] for accessing elements of array instance created without const
            const T &operator[](const int index) const; // operator[] for accessing elements of array instance created with const

            static unsigned int DefaultSize();           // get the default_size variable
            static void DefaultSize(const unsigned int size); // set the default_size variable
        };
    }
}

// Using the following code enables to include Array.cpp file into the header file
// This makes sure that the linker is able to find Array.cpp at the time of compilation
// And it helps to maintian the consistency of including .hpp file in the main()

#ifndef Array_cpp
#include "Array.cpp"
#endif

#endif