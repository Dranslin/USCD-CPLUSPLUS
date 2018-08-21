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
    int index;
    // Traverses along the string until null character
    for (index = 0; s1[index] != '\0'; index++)
        ;
    return (size_t)(index);
}
