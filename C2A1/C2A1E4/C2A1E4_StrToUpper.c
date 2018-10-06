/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 09/29/2018
 * C2A1E4_StrToUpper.c
 * Win 10
 * Visual C++ 2017
 *
 * Converts supplied source string to the upppercase equivalent in 
 * the dest string, and returns the length of the dest string.
 */

#include <stdio.h>
#include <ctype.h>

size_t StrToUpper(char *dest, const char *source)
{
    const char *holder = dest;          // Holds position of string for size
    // Walks through string, copying upper-case source to dest
    for (; (*dest = toupper(*source)) != '\0'; dest++, source++)
        ;
    return (size_t)(dest - holder);     // get size
}
