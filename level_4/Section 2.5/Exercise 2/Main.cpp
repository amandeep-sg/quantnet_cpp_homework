// Main.cpp
// program to create an array of pointers, pointing to instances of Point class
// assign and print instance of Point to each element of the array
// delete the instance of the Point objects one by one using for loop
// view memory_diagram.jpg file to understand how pointers work in the program
//
// author: amandeep singh gujral

#include <iostream>
#include "Point.hpp"

using namespace std;

int main()
{
     Point **p_arr;          // variable to store pointer to Point pointer
     p_arr = new Point *[3]; // array of pointers, pointing to Point pointers

     if (p_arr == nullptr) // check if the array is initialised or not
     {
          cout << "error: insufficient memory!" << endl;
     }
     else
     {
          for (int i = 0; i < 3; i++) // iterate to assign Point object to all the elements of the array
          {
               p_arr[i] = new Point(i, i);
               cout << *p_arr[i] << endl; // print the elements onf the array
          }
          cout << endl;
     }

     for (int i = 0; i < 3; i++)// iterate to delete all the elements of the array one by one
     {
          delete p_arr[i]; 
     }
     delete[] p_arr; // delete array of pointers

     return 0;
}