// Main.c
// c program to compute the length of the string
// the custom implementation should be similar to built-in strlen() function
//
// author: amandeep singh gujral

#include <stdio.h>
#define MAXLINE 30 // String lenght declaration
int Length(const char str[]);
int main()
{
    char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
    int c;                    // The input character
    int i = 0;                // The counter

    // Print intro text
    printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

    // Get the characters
    while ((c = getchar()) != EOF && i < MAXLINE)
    {
        // Append entered character to string
        string[i++] = (char)c;
    }
    string[i] = '\0';

    printf("\n");
    // String must be closed with \0
    printf("String length is %d\n", Length(string));
    return 0;
}
/* Implement the Length() function here */

int Length(const char *str)
{
    const char *s = str; // assign the pointer of the first element of str to char pointer variable s
    while (*s != '\0')   // keep on increment pointer s until it points to last char of string i.e *s != '\0
    {
        s++;
    }

    return s - str; // difference of pointer to the of last char of string and the pointer to the first char of the string
}