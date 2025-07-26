// c program to compute the factorial of a whole number using recurssive function
//
// author: amandeep singh gujral

#include <stdio.h> // c style I/O

long int factorial(int num) // factorial function using recursive function
{
    if (num <= 0) // terminal critria
    {
        return 1;
    }
    return num * factorial(num - 1);
}

int main()
{
    int n;
    printf("Enter the number: \n");
    scanf("%i", &n);
    printf("\nfactorial: %li\n", factorial(n));
    return 0;
}