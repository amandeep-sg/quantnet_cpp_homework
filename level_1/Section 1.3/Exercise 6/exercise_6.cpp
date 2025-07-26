// c program to shift any integer two places to the right
// check if the shift is airthmatic or logical
//
// author: amandeep singh gujral

#include <stdio.h> // c style I/O

int main()
{
    int num;

    printf("Enter an integer: \n");
    scanf("%i", &num); // capture number entered by the user in the console

    num = num >> 2; // shift the integer by two places to the right
    printf("integer >> 2 evaluates to: %i\n", num);

    if (num < 0) // check if the shift is airthmatic or logical
    {
        printf("It is an airthmatic shift\n");
    }
    else
    {
        printf("It is an logical shift\n");
    }
    return 0;
}