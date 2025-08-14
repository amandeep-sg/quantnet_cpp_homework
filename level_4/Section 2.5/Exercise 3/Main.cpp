// Main.cpp
// program to create instance of Array class using default constructor, constructor with size and copy constructor
// set and get the element of an Array instance using SetElement and GetElement memeber function
// get the size of the Array instance using Size member function
// show the usage of operator[] overload with const and without const
// used assignment operator to copy all the element of one array to another. Then print elements in colsole using for loop
//
// author: amandeep singh gujral

#include <iostream>

#include "Point.hpp"
#include "Array.hpp"

using namespace std;

int main()
{
     Array d_arr;                      // array instance is created of default size 5, using default constructor
     Array p_arr(3);                   // array instance is created of size 3, using constructor with size argument
     p_arr.SetElement(1, Point(2, 3)); // set element Point(2,3) at index 1

     const Array c_arr(p_arr); // const copy array is created using copy constructor

     cout << endl;
     cout << "size of array instance created using default constructor: " << d_arr.Size() << endl;

     cout << endl;

     cout << "point at index 1 of d_arr: " << d_arr.GetElement(1) << endl;
     cout << "point at index 1 of p_arr: " << p_arr[1] << endl; // operator[] without const is called
     cout << "point at index 1 of c_arr: " << c_arr[1] << endl; // operator[] with const is called

     // the const Point& operator[](int index) const is needed to get the elements of Array instance created as const  ex. c_arr

     cout << endl;

     p_arr = d_arr; // copy array using assignment operator

     for (int i = 0; i < 5; i++) // for loop to print the element of the array
     {
          cout << p_arr.GetElement(i) << endl;
     }

     return 0;
}