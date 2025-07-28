// Main.c
// program to reads the characters from the keyboard
// write them in a file on press of 'enter' (or 'return)
//
// author: amandeep singh gujral

#include <stdio.h>   // c style I/O
#include <string.h>  //c style string
#include <stdbool.h> // c style boolean

// define max length of the user input
#define MAX_LENGTH 1000

FILE *Create_File();                                  // function declaration to take file name input and create .txt file
void Write_File(int *arr, int *char_count, FILE *fp); // function declaration to write user input to a .txt file

int main()
{
    int input;
    int char_count = 0;    // no of characters in the line
    int store[MAX_LENGTH]; // array to store the characters typed by the user
    FILE *fp;
    fp = Create_File();
    if (fp == NULL) // check if the file is created or not
    {
        printf("Error: Not able to create file\n");
        return 0;
    }

    printf("Start typing...\n");

    while ((input = getchar()) != EOF && input != 1 && input != 4 && input != 26)
    {
        if (input == 10) // check if the user has pressed entered. If yes, start printing the characters
        {
            Write_File(store, &char_count, fp);
            char_count = 0; // set the char_count to 0 for memory management
        }
        else
        {
            store[char_count++] = input; // push characters to the back of the store
        }
    }
    printf("CTRL + A is a correct ending.");
    fclose(fp);
    return 0;
}

// define Create_File function
// returns pointer to the file to perform write operation
FILE *Create_File()
{
    int input;
    int char_count = 0;
    char file_name[51]; // array to store the file name entered by the user

    printf("Type file name(upto 50 characters) & press enter (or return): \n");
    while ((input = getchar()) != 10)
    {
        file_name[char_count++] = (char)input; // push characters to the back of the filename
    }
    printf("\n");
    char_count = 0;
    strcat(file_name, ".txt");        // concat .txt to filename
    FILE *fp = fopen(file_name, "w"); // create file
    return fp;
}

// define Write_File function
void Write_File(int *arr, int *char_count, FILE *fp)
{
    for (int i = 0; i < *char_count; i++) // loop through the store array to print the characters typed in by the user
    {
        fputc(arr[i], fp); // write characters to the file
    }
    fputc('\n', fp);
}