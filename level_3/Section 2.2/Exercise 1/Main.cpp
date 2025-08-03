// Main.cpp
// program to Ask the user for the x-coordinate and y-coordinates of two point
// set the coordinates entered by the user using the setter functions
// print the description of the point returned by the ToString() function
// print the point coordinates using the get functions
//
// author: amandeep singh gujral

#include <iostream>
#include "Point.hpp"

using namespace std;

int main()
{
    // Prompt user to enter x and y coordinated of a point
    double x, y;
    cout << "Enter x coordinate of a point" << endl;
    cin >> x;
    cout << "Enter y coordinate of a point" << endl;
    cin >> y;

    Point point_a; // create instance of Point class named point_a with x = 0.00 and y = 0.00

    point_a.SetX(x); // set the value of x coordinate of point_a entered by the user
    point_a.SetY(y); // set the value of y coordinate of point_a entered by the user

    cout << "Description of the point using ToString(): " << point_a.ToString() << endl; // print description of the point_a

    cout << "x coordinate using GetX(): " << point_a.GetX() << endl; // print x coordinate of the point_a
    cout << "y coordinate using GetY(): " << point_a.GetY() << endl; // print y coordinate of the point_a

    return 0;
}