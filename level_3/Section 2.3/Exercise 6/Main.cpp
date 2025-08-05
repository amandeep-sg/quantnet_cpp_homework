// Main.cpp
// program to Ask the user for the center point and raidus of the circl
// print the description of the circle returned by the ToString() function
// print the diameter of the circle
// print the area of the circle
// print the circumferenc of the circle
//
// author: amandeep singh gujral

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"

using namespace std;

int main()
{
    double x, y;

    // Prompt user to enter x and y coordinated of a first point i.e. point_a
    cout << "Enter x coordinate of center of circle" << endl;
    cin >> x;
    cout << "Enter y coordinate of center of circle" << endl;
    cin >> y;

    Point center(x, y); // create instance of center point of the circle

    // Prompt user to enter raidus of the circle
    cout << "Enter the raidus of the circle (Note: raidus should be whole number):" << endl;
    cin >> x;

    cout << endl;

    Circle circle(center, x);

    cout << endl;

    cout << "Description of the circle: " << circle.ToString() << endl;        // print description of the circle
    cout << "Diameter of the circle: " << circle.Diameter() << endl;           // print diameter of the circle
    cout << "Area of the circle: " << circle.Area() << endl;                   // print area of the circle
    cout << "Circumference of the circle: " << circle.Circumference() << endl; // print circumference of the circle
    cout << endl;

    return 0;
}