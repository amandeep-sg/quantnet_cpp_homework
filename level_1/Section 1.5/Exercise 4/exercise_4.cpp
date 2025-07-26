// c program to print number input by the user, one character at a time using recurssive function
//
// author: amandeep singh gujral

#include <stdio.h>

int printnumber(int num) // function to print integers
{
    if (num <= 0) // terminal condition
    {
        return 0;
    }
    printnumber(num / 10);     // next recurssion
    putchar('0' + (num % 10)); // print integer
    return 0;
}

int main()
{
    int num;
    printf("Enter an integer: \n");
    scanf("%i", &num);
    if (num > 0) // for positive integers
    {
        printnumber(num);
    }
    else if (num == 0) // check if integer entered is zero
    {
        putchar('0');
    }
    else // for negative integers
    {
        putchar('-');
        printnumber((num * -1));
    }
    printf("\n");
    return 0;
}