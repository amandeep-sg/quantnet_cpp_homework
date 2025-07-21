#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    unsigned int count_char = 0, count_word = 0, count_newline = 1;
    int input, prev_char = 0;
    bool is_word = false;
    while ((input = getchar()) != EOF && input != 26 && input != 4)
    {
        if (input == 10 || input == 13) // This condition is introduced to increment the count of newline whithout increment char count.
        {
            count_newline++;
            if (!isspace(prev_char) && prev_char != '\0') // check if previous char is not a whitespace or null
            {
                is_word = true;
            }
        }
        else if (isspace(input))
        {
            count_char++;
            if (!isspace(prev_char) && prev_char != '\0') // check if previous char is not a whitespace or null.
            {
                is_word = true;
            }
        }
        else
        {
            count_char++;
        }

        if (is_word) // increase word count if is_word flag is set to true. After increment, reset the flag to false.
        {
            count_word++;
            is_word = false;
        }
        prev_char = input;
    }

    if (!isspace(prev_char) && prev_char != '\0') // count last word if not terminated by whitespace or null.
    {
        count_word++;
    }

    printf("\n");
    printf("No of characters: %i\n", count_char);
    printf("No of words: %i\n", count_word);
    printf("No of new lines: %i\n", count_newline);
    return 0;
}