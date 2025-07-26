// c program to get input of two real numbers and print their differance upto two decimal places
//
// author: amandeep singh gujral
#include <stdio.h> // c style I/O

double minus(double a, double b) // minus function to calculate the differance of two real numbers
{
    return a - b;
}

int main()
{
    double a, b;
    printf("Enter first number: \n");
    scanf("%lf", &a);
    printf("Enter second number: \n");
    scanf("%lf", &b);
    printf("The differance is: %.2lf\n", minus(a, b)); // print the differance
    return 0;
}