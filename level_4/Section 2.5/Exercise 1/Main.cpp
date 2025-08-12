// Main.cpp
// program to create pointers to Point object
// The pointers point to instance of Point object created on heap
// Instance of Point are created using default constructor, constructor with coordinates and copy constructor
//
// author: amandeep singh gujral

#include <iostream>
#include "Point.hpp"

using namespace std;

int main()
{
     Point *point_a, *point_b, *point_c; // pointers of type Point

     // point created on heap using default constructor
     point_a = new Point();
     cout << *point_a << endl;
     cout << "distance of point a from origin: " << point_a->Distance() << endl;

     // point created on heap using constructor with coordinates
     point_b = new Point(3.50, 9.80);
     cout << *point_b << endl;
     cout << "distance of point a from origin: " << point_b->Distance() << endl;

     // point created on heap using copy constructor
     point_c = new Point(*point_b);
     cout << *point_c << endl;
     cout << "distance of point a from origin: " << point_c->Distance() << endl;

     cout << "distance between point a and point b: " << point_b->Distance(*point_a) << endl;
     cout << endl;

     // initialise variable size array with default constructor
     // Array in the heap can only be created with the default constructor
     int size; // size of the array
     cout << "Enter the size of the array: " << endl;
     cin >> size;

     Point *p_arr;            // pointer of type Point
     p_arr = new Point[size]; // initialise array of type Point and of length = size

     cout << endl;

     if (p_arr == nullptr) // check if the array is initialised
     {
          cout << "error: insufficient memory!" << endl;
     }
     else
     {
          for (int i = 0; i < size; i++) // iterate over p_arr to print all the elements of the array
          {
               cout << p_arr[i] << endl;
          }
     }

     cout << endl;

     // delete instance of the points created
     delete point_a;
     delete point_b;
     delete point_c;

     // delete all the elements or p_arr
     delete[] p_arr;
     return 0;
}