// c program to print the output of the airthmatic claculations
//
// author: amandeep singh gujral

#include <stdio.h> // c syle I/O

int main()
{
    int x;
    x = -3 + 4 * 5 - 6;
    printf("x=%d\n", x); // -3 + 20 - 6 = 11 | Output will be: 11

    x = 3 + 4 % 5 - 6;
    printf("x=%d\n", x); // 3 + 4 - 6 = 1 | Output will be: 1

    x = -3 * 4 % -6 / 5;
    printf("x=%d\n", x); // (-12 % -6) / 5 = 0 | Output will be: 0

    x = (7 + 6) % 5 / 2;
    printf("x=%d\n", x); // (13 % 5) / 2 = 1 | Output will be: 1

    return 0;
}