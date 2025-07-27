// Main.c
// program to reads the characters from the keyboard and print them in terminal on press of 'enter' (or 'return)
//
// author: amandeep singh gujral

#include <stdio.h>   // c style I/O
#include <stdbool.h> // c style boolean

// define max length of the user input
#define MAX_LENGTH 1000

bool Push(int *arr, int *count, int *val);

int main()
{
    int input;
    int char_count = 0;    // no of characters in the line
    int store[MAX_LENGTH]; // array to store the characters typed by the user

    printf("Start typing...\n");

    while ((input = getchar()) != EOF && input != 1 && input != 4 && input != 26)
    {
        if (input == 10) // check if the user has pressed entered. If yes, start printing the characters
        {
            for (int i = 0; i < char_count; i++) // loop through the store array to print the characters typed in by the user
            {
                putchar(store[i]);
            }
            printf("\n\n");
            char_count = 0; // set the char_count to 0 for memory management
        }
        else
        {
            Push(store, &char_count, &input); // push characters to the back of the store
        }
    }
    printf("CTRL + A is a correct ending.");
    return 0;
}

// define Push function to push the character to the back of the array (i.e. store)
bool Push(int *arr, int *count, int *val)
{
    if (*count >= MAX_LENGTH) // check if the array is full
    {
        return false;
    }
    arr[*count] = *val; // add value to the back of the array
    (*count)++;         // increment the count of characters added
    return true;        // return true if the value is added to the
}