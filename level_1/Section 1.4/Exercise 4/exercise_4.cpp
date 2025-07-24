#include <stdio.h>

double convert(int &temp)
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

    printf("| Fahrenheit | Celsius  |\n");
    printf("|------------|----------|\n");

    while (start <= end)
    {
        printf("| %11i|%10.1f|\n", start, convert(start));
        start = start + step_size;
    }

    return 0;
}