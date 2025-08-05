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
#include "Line.hpp"

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
    
    cout << endl;

    Line line(point_a, point_b);

    cout << endl;

    cout << "Description of the line: " << line.ToString() << endl; // print description of the point_b

    cout << endl;

    cout << "Length of the line: " << line.Length() << endl; // distance of point_b from origin

    cout << endl;
    return 0;
}