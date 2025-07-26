// c program to multiply the integer with 2^n, where n is the power defined by the user using left shift
//
// author: amandeep singh gujral

#include <stdio.h> //c style I/O

int main()
{
    int num, power;
    printf("Enter an integer: \n");
    scanf("%i", &num);
    printf("Enter the power: \n");
    scanf("%i", &power);
    num = num << power; // set num equal to num shifted by power to the left
    printf("Final result for (num * (2 ^ %i)): %i\n", power, num);
    return 0;
}