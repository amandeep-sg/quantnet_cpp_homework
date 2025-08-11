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

     // Note: this code will compile and run 
	// during execution, 1.0 in the if statement is implicitly converted to a Point object, therefore being equal
	//Point p(1.0, 1.0);
	//if (p == 1.0) cout << "Equal!" << endl;
	//else cout << "Not equal" << endl;

     //output: 
     //Constructor called: New point created with x==y!
     //Equal!


     //code from the exercise
     Point p(1.0, 1.0); 
     if (p==(Point)1.0) cout<<"Equal!"<<endl; 
     else cout<<"Not equal"<<endl; 


     return 0;
}