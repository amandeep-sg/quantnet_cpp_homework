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
        if(i !=5){
            printf("count of number %i: %i\n", i, count[i]);
        } else{
            printf("count of other char: %i\n", count[i]);
        }
    }

    return 0;
}