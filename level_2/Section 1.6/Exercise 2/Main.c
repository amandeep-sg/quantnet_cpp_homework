// Main.c
// c program to compute the maximum between 2 and 3 numbers using macros
// achieved using two macros, MAX2 and MAX3
// author: amandeep singh gujral

#include <stdio.h> // c style I/O
#include "Defs.h"

int main()
{
    int num1 = 20;
    int num2 = 32;
    int num3 = 48;

    // find and print the max number between num2 and num3
    printf("Max number between num1 and num2: %i\n", MAX2(num1, num2));

    // find and print the max number between num1, num2 and num3
    printf("Max number between num1, num2 and num3: %i\n", MAX3(num1, num2, num3));
    return 0;
}