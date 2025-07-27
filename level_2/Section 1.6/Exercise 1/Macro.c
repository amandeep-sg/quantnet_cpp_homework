// Macro.c
// c progra to print variables using macro
// the first print macro call prints variable a and the secons print macro call prints variable a and b
// Printing is executed by using PRINT1 and PRINT2 macros
//
// author: amandeep singh gujral
//

// pre processors
#include <stdio.h> // c style I/O
#include "Defs.h"  // include file from Defs.h

int main()
{
    PRINT1(20);     // print integer 20 using PRINT1 macro
    PRINT2(10, 20); // print integer 10 and 20 using PRINT2 macro
    return 0;
}