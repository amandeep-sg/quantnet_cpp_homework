// c program to convert temp in fahrenheit to celsius from 0°f to 19°f with a step size of 1°f
//
// author: amandeep singh gujral

#include <stdio.h> // c style I/O

double convert(int &temp)
{
    return (5.0 / 9.0) * (temp - 32);
}

int main()
{

    int start = 0, end = 19, step_size = 1;

    printf("| Celsius   | Fahrenheit|\n"); // table header
    printf("|-----------|-----------|\n"); // spacer

    for (int i = start; i <= end; i += step_size)
    {
        printf("| %10.1f|%11i|\n", convert(start), start);
        start += step_size; // increases the temp by the stepsize
    }

    return 0;
}