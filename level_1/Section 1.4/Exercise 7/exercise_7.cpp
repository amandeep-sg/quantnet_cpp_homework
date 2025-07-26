// c program to count numbers from 0-4 and use default to count the number of other characters.
// the frequency of number 3 is shown in words.
// Ex: Number three appears two times.
// Only print the frequency when it is smaller than three.
// If the frequency is three or larger, then print: "The number three appears more than two times."
//
// author: amandeep singh gujral

#include <stdio.h> // c style I/O

int main()
{
    int input, count[6] = {0, 0, 0, 0, 0, 0};

    printf("Type the integers: \n");

    while ((input = getchar()) != EOF && input != 26 && input != 4)
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
        case 51: // input == 3
            count[3]++;
            break;
        case 52: // input == 4
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
        switch (i)
        {
        case 0:
        case 1:
        case 2:
        case 4:
            printf("count of number %i: %i\n", i, count[i]);
            break;
        case 3:
            switch (count[3])
            {
            case 0:
                printf("Number three appears zero time\n");
                break;
            case 1:
                printf("Number three appears one time\n");
                break;
            case 2:
                printf("Number three appears two times\n");
                break;
            default:
                printf("Number three appears more than two time\n");
                break;
            }
            break;
        case 5:
            printf("count of other char: %i\n", count[i]);
            break;
        }
    }

    return 0;
}