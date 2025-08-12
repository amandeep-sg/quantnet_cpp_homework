// Main.cpp
// program to Ask the user for the x-coordinate and y-coordinates of two point
// set the coordinates entered by the user using the setter functions
// print the description of the point returned by the ToString() function
// print the point coordinates using the get functions
// print the distance of both the points from origin
// print the distance between the two points
//
// author: amandeep singh gujral

#include <iostream>
#include "Point.hpp"

using namespace std;

int main()
{
     Point *point_a, *point_b, *point_c;

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

     // initialise variable size array with default constructor
     //Array in the heap can only be created with the default constructor
     cout << endl;
     int size;
     cout << "Enter the size of the array: " << endl;
     cin >> size;
     Point *p_arr;
     p_arr = new Point[size];

     cout << endl;

     for (int i = 0; i < size; i++)
     {
          cout << p_arr[i] << endl;
     }
     cout << endl;

     // delete instance of the points created
     delete point_a;
     delete point_b;
     delete point_c;
     delete[] p_arr;
     return 0;
}