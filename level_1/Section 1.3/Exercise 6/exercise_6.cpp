#include <stdio.h>

int main()
{
    int num;

    printf("Enter an integer: \n");
    scanf("%i", &num);

    num = num >> 2;
    printf("integer >> 2 evaluates to: %i\n", num);

    if (num < 0)
    {
        printf("It is an airthmatic shift\n");
    }
    else
    {
        printf("It is an logical shift\n");
    }
    return 0;
}