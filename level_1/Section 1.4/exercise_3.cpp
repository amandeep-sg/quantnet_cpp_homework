#include <stdio.h>
#include <ctype.h>

int main()
{
    unsigned int count_char = 0, count_word = 0, count_newline = 1;
    int input, prev_char = 0;
    bool is_word = false;
    printf("Start typing: \n");
    while ((input = getchar()) != EOF && input != 26 && input != 4)
    {
        count_char++;
        switch (isspace(input))
        {
        case 1:
            switch (isspace(prev_char))
            {
            case 1:
                break;
            case 0:
                switch ((prev_char == '\0') ? 1 : 0)
                {
                case 0:
                    count_word++;
                    break;
                }
                break;
            }
        }

        switch (input)
        {
        case 10:
        case 13:
            count_newline++;
            count_char--;
            break;
        }
        prev_char = input;
    }

    switch (isspace(prev_char)) // increase word count if last word is not a whitespace
    {
    case 0:
        count_word++;
        break;
    }

    printf("\n");
    printf("No of characters: %i\n", count_char);
    printf("No of words: %i\n", count_word);
    printf("No of new lines: %i\n", count_newline);
    return 0;
}