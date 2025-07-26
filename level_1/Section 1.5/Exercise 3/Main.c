// c program to demonstrate the use of header file
//
// author: amandeep singh gujral

#include <stdio.h> // c style I/O
#include "Print.h" // import from Print.h header file

int main()
{
    int num;
    printf("Enter an integer: \n");
    scanf("%i", &num);
    print(num); // custom function to multiply integer by 2 and print the result to console
    return 0;
}