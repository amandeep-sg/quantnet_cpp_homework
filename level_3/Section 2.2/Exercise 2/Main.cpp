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
    // Prompt user to enter x and y coordinated of a first point i.e. point_a
    double x, y;
    cout << "Enter x coordinate of first point" << endl;
    cin >> x;
    cout << "Enter y coordinate of first point" << endl;
    cin >> y;

    Point point_a; // create first instance of Point class named point_a with x = 0.00 and y = 0.00

    point_a.SetX(x); // set the value of x coordinate of point_a entered by the user
    point_a.SetY(y); // set the value of y coordinate of point_a entered by the user

    // Prompt user to enter x and y coordinated of a second point i.e. point_b
    cout << "Enter x coordinate of second point" << endl;
    cin >> x;
    cout << "Enter y coordinate of second point" << endl;
    cin >> y;

    Point point_b; // create second instance of Point class named point_b with x = 0.00 and y = 0.00

    point_b.SetX(x); // set the value of x coordinate of point_a entered by the user
    point_b.SetY(y); // set the value of y coordinate of point_a entered by the user

    cout << "Description of the point using ToString(): " << point_a.ToString() << endl; // print description of the point_a

    cout << "x coordinate using GetX(): " << point_a.GetX() << endl; // print x coordinate of the point_a
    cout << "y coordinate using GetY(): " << point_a.GetY() << endl; // print y coordinate of the point_a
    cout << endl;

    cout << "Description of the point using ToString(): " << point_b.ToString() << endl; // print description of the point_b

    cout << "x coordinate using GetX(): " << point_b.GetX() << endl; // print x coordinate of the point_b
    cout << "y coordinate using GetY(): " << point_b.GetY() << endl; // print y coordinate of the point_b

    cout << "Distance of first point from origin: " << point_a.DistanceOrigin() << endl;  // distance of point_a from origin
    cout << "Distance of second point from origin: " << point_b.DistanceOrigin() << endl; // distance of point_b from origin

    // distance between point_a and point_b
    cout << "Distance between first and second point: " << point_a.Distance(point_b) << endl;
    ;

    return 0;
}