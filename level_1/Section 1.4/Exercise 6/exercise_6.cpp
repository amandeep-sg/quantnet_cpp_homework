// c program to count numbers from 0-4 and use default to count the number of other characters.
//
// author: amandeep singh gujral

#include <stdio.h> // c style I/O

int main()
{
    int input, count[6] = {0, 0, 0, 0, 0, 0};

    printf("Type the integers: \n");

    while ((input = getchar()) != EOF && input != 26 && input != 4) //// break the while loop if ctrl+D pressed
    {
        switch (input)
        {
        case 48: // input == 0
            count[0]++;
            break;
        case 49: // input == 1
            count[1]++;
            break;
        case 50: // input == 2
            count[2]++;
            break;
        case 51: // input ==3
            count[3]++;
            break;
        case 52: // inpu == 4
            count[4]++;
            break;
        default: // for remaining characters
            count[5]++;
            break;
        }
    }

    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        if (i != 5)
        {
            printf("count of number %i: %i\n", i, count[i]);
        }
        else
        {
            printf("count of other char: %i\n", count[i]);
        }
    }

    return 0;
}