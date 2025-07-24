#include <stdio.h>
#include "Print.h"

int main()
{
    int num;
    printf("Enter an integer: \n");
    scanf("%i", &num);
    print(num);
    return 0;
}