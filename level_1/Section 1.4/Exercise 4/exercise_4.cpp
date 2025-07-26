// c program to convert temp in fahrenheit to celsius
//
// author: amandeep singh gujral

#include <stdio.h> // c style I/O

double convert(int &temp) // function to convert temp in fahrenheit to celsius
{
    return (5.0 / 9.0) * (temp - 32);
}

int main()
{
    int start, end, step_size;
    printf("Enter start temp (in Fahrenheit): \n");
    scanf("%i", &start);

    printf("Enter end temp (in Fahrenheit): \n");
    scanf("%i", &end);

    printf("Enter step size: \n");
    scanf("%i", &step_size);

    printf("| Fahrenheit | Celsius  |\n"); // table header
    printf("|------------|----------|\n"); // spacer

    while (start <= end)
    {
        printf("| %11i|%10.1f|\n", start, convert(start));
        start = start + step_size; // increases the temp by the user defined stepsize
    }

    return 0;
}