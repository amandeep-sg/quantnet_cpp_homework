#include <stdio.h>

double convert(int &temp)
{
    return (5.0 / 9.0) * (temp - 32);
}

int main()
{

    int start = 0, end = 19, step_size = 1;

    printf("| Celsius   | Fahrenheit|\n");
    printf("|-----------|-----------|\n");

    for (int i = start; i <= end; i += step_size)
    {
        printf("| %10.1f|%11i|\n", convert(start), start);
        start += step_size;
    }

    return 0;
}