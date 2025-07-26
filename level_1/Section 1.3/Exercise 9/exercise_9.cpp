// c program to perform the airthmatic operations and predict the outcome
//
// author: amandeep singh gujral
#include <stdio.h> // c style I/O

int main()
{
    int x = 1;
    int y = 1;
    int z = 1;

    x += y += x;
    printf("%d\n\n", (x < y) ? y : x);   // Number 1: prints 3 as x > y
    printf("%d\n", (x < y) ? x++ : y++); // Number 2: prints 2 as x > y and it is a post-increment. Now value of y = 3
    printf("%d\n", x);                   // Number 3: prints 3 as x++ never executed in the above logic
    printf("%d\n", y);                   // Number 4: prints 3
    return 0;
}