#include <stdio.h>

int main()
{
    int i = 10;
    printf("Pre-decrement\n");
    printf("i: %i\n", i);
    printf("--i: %i\n\n", --i); // output will be: 9

    i = 10;
    printf("Post-decrement\n");
    printf("i: %d\n", i);
    printf("i--: %d\n", i--); // output will be: 10
    printf("i: %d\n", i);     // output will be: 9
    return 0;
}