/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/20/2018
 * C1A6E1_MyStrlen.c
 * Win 10
 * Visual C++ 2017
 *
 * Traverses along the addresses of s1 to find the difference between
 * beginning of s1 and end of s1 and returns that difference as size_t
 */

#include <string.h>

size_t MyStrlen(const char *s1)
{
    const char * const holder = s1; // Holds start position of string

    // Moves address of s1 along the string, used to count length
    for (; *s1 != '\0'; s1++)
        ;

    return (size_t)(s1 - holder);
}
