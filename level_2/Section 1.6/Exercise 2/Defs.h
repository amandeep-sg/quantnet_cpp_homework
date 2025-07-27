// Defs.h
//  c program to define macros MAX2 and MAX3 in an include file
//
//  author: amandeep singh gujral

#ifndef Defs_H
#define Defs_H

// defination of MAX2: find max between two variables
#define MAX2(var1, var2) (var1 > var2 ? var1 : var2)

// defination of MAX3: find max between three numbers
#define MAX3(var1, var2, var3) (MAX2(var1, var2) > var3 ? MAX2(var1, var2) : var3)

#endif