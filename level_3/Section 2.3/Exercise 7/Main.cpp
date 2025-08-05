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

    // x and y coordinate of point_a
    cout << "x coordinate : " << point_a.X() << endl; // print x coordinate of the point_a
    cout << "y coordinate : " << point_a.Y() << endl; // print y coordinate of the point_a
    cout << endl;

    // x and y coordinate of point_b
    cout << "x coordinate : " << point_b.X() << endl; // print x coordinate of the point_a
    cout << "y coordinate : " << point_b.Y() << endl; // print y coordinate of the point_a
    cout << endl;

    // updating x and y coordinate of point_b
    cout << "updating point_b to Point(1,1)" << endl;
    point_b.X(1);
    point_b.Y(1);

    cout << "Description of the first point: " << point_a.ToString() << endl;  // print description of the point_a
    cout << "Description of the second point: " << point_b.ToString() << endl; // print description of the point_b

    cout << endl;

    cout << "Distance of first point from origin: " << point_a.Distance() << endl;  // distance of point_a from origin
    cout << "Distance of second point from origin: " << point_b.Distance() << endl; // distance of point_b from origin

    cout << endl;

    // distance between point_a and point_b
    cout << "Distance between first and second point: " << point_a.Distance(point_b) << endl;

    cout << endl;

    return 0;
}