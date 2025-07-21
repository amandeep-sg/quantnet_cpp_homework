#include <stdio.h>

int main()
{
    int num, power;
    printf("Enter an integer: \n");
    scanf("%i", &num);
    printf("Enter the power: \n");
    scanf("%i", &power);
    num = num << power;
    printf("Final result for (num * (2 ^ 4)): %i\n", num);
    return 0;
}