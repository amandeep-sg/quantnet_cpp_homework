#include <stdio.h>

int main()
{
    int input, count[6] = {0, 0, 0, 0, 0, 0};

    while ((input = getchar()) != EOF && input != 26 && input != 4)
    {
        switch (input)
        {
        case 48:
            count[0]++;
            break;
        case 49:
            count[1]++;
            break;
        case 50:
            count[2]++;
            break;
        case 51:
            count[3]++;
            break;
        case 52:
            count[4]++;
            break;
        default:
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