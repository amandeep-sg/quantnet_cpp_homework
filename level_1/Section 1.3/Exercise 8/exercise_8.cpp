#include <stdio.h>

int main()
{
    int x = 2;
    int y;
    int z;
    x *= 3 + 2;
    printf("x=%d\n", x); // x = 10

    x *= y = z = 4;
    printf("x=%d\n", x); // x = 40, y = 4, z = 4

    x = y == z;
    printf("x=%d\n", x); // x = 1 , y==z evaluates to 1

    return 0;
}