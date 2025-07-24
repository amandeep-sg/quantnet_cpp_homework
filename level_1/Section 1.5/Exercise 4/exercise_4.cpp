#include <stdio.h>

int printnumber(int num)
{
    if (num <= 0)
    {
        return 0;
    }
    printnumber(num / 10);
    putchar('0' + (num % 10));
    return 0;
}

int main()
{
    int num;
    printf("Enter an integer: \n");
    scanf("%i", &num);
    if (num > 0)
    {
        printnumber(num);
    }
    else if (num == 0)
    {
        putchar('0');
    }
    else
    {
        putchar('-');
        printnumber((num * -1));
    }
    printf("\n");
    return 0;
}