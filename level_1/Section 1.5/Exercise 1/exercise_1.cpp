#include <stdio.h>

double minus(double a, double b)
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
    printf("The differance is: %lf\n", minus(a, b));
    return 0;
}