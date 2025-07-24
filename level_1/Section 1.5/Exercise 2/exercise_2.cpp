#include <stdio.h>

long int factorial(int num)
{
    if (num <= 0)
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