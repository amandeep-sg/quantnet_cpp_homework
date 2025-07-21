#include <stdio.h>
int main()
{
    float base = 0;
    float height = 0;

    printf("Enter the base of the right angled triangle: ");
    scanf("%f", &base);
    printf("Enter the  height of the right angled triangle: ");
    scanf("%f", &height);
    printf("Surface area of the right angled triangle: %f \n", (.5 * height * base));
    return 0;
}
