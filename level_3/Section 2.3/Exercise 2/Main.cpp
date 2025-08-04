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
    double x, y;

    // Prompt user to enter x and y coordinated of a first point i.e. point_a
    cout << "Enter x coordinate of first point" << endl;
    cin >> x;
    cout << "Enter y coordinate of first point" << endl;
    cin >> y;

    Point point_a(x, y); // create instance of point_a

    // Prompt user to enter x and y coordinated of a second point i.e. point_b
    cout << "Enter x coordinate of second point" << endl;
    cin >> x;
    cout << "Enter y coordinate of second point" << endl;
    cin >> y;

    Point point_b(x, y); // create instance of point_b

    cout << "Description of the first point: " << point_a.ToString() << endl;  // print description of the point_a
    cout << "Description of the second point: " << point_b.ToString() << endl; // print description of the point_b

    cout << endl;

    cout << "Distance of first point from origin: " << point_a.DistanceOrigin() << endl;  // distance of point_a from origin
    cout << "Distance of second point from origin: " << point_b.DistanceOrigin() << endl; // distance of point_b from origin

    cout << endl;

    // distance between point_a and point_b
    cout << "Distance between first and second point: " << point_a.Distance(point_b) << endl;

    cout << endl;

    // observations:
    // when calling member function Distance(), the copy constructor is called
    // to no of constructor calls is equal to no of destructor calls
    // 2 constructor calls for instantiating poinr_a and point_b.
    // copy constructor is not called.
    // 2 distructor calls 1 for point_b and 1 for point_a

    return 0;
}