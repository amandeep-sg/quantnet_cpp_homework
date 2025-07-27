// Main.c
// program to print day name for given number from the range [1, 7]
//
// author: amandeep singh gujral

#include <stdio.h> // c style I/O

char *DayName(const int *num); // declaration fo the DayName function

int main()
{
    int num = 6;

    if (num > 0 && num < 8) // check if the day number is from the range [1,7]
    {
        printf("Day %i is a %s\n", num, DayName(&num));
    }
    else // error handling in case num is not from the range [1,7]
    {
        printf("Invalid day number. Day number shouled be between [1,7]\n");
    }
    return 0;
}

// day name function, take in pointer to integer variable num and returns day anme string.
char *DayName(const int *num)
{
    char *day_name_mapper[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return day_name_mapper[(*num) - 1];
}