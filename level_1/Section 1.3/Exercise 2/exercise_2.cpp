// c program to get input of base and hight of the right angled triangle from the user in console
// print the surface area of the right angled triangle
//
//  author: amandeep singh gujral

#include <stdio.h> // c style I/O
int main()
{
    float base = 0;   // base of the triangle initialized as zero
    float height = 0; // height of the triangle initialised as zero

    printf("Enter the base of the right angled triangle: ");
    scanf("%f", &base);
    printf("Enter the  height of the right angled triangle: ");
    scanf("%f", &height);
    printf("Surface area of the right angled triangle: %f \n", (.5 * height * base)); // print the surface area of the triangle
    return 0;
}
