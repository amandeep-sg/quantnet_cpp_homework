// c program to pre increment and post increment a variable by 1 unit
//
// author: amandeep singh gujral
#include <stdio.h> //c style I/O

int main()
{
    int i = 10;
    printf("Pre-decrement\n");
    printf("i: %i\n", i);
    printf("--i: %i\n\n", --i); // output will be: 9

    i = 10; // assign new value to variable i
    printf("Post-decrement\n");
    printf("i: %d\n", i);
    printf("i--: %d\n", i--); // output will be: 10
    printf("i: %d\n", i);     // output will be: 9
    return 0;
}