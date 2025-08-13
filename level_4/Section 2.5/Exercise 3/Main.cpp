// Main.cpp
// program to create an array of pointers, pointing to instances of Point class
// assign and print instance of Point to each element of the array
// delete the instance of the Point objects one by one using for loop
// view memory_diagram.jpg file to understand how pointers work in the program
//
// author: amandeep singh gujral

#include <iostream>

#include "Point.hpp"
#include "Array.hpp"

using namespace std;

int main()
{
     Array p_arr(3);
     p_arr.SetElement(1, Point(2, 3));

     const Array n_arr(p_arr);

     cout << p_arr[1] << endl;
     cout << n_arr[1] << endl;

     cout << endl;

     for (int i = 0; i < 3; i++)
     {
          cout << p_arr.GetElement(i) << endl;
     }

     return 0;
}