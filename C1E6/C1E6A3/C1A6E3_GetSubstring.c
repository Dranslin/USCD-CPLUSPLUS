/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/20/2018
 * C1A6E3_GetSubstring.c
 * Win 10
 * Visual C++ 2017
 *
 * Extracts a substring from a larger string and returns the extracted
 * substring. This accounts for negitive starting value or zero value
 * and if going beyond full string, ends the process and returns what
 * was copied.
 */

#include <string.h>

char *GetSubstring(const char source[], int start, int count, char result[])
{
    char *localVar = result;

    if (start > 0) // Skip if 0 so that first letter isn't lost
    {
        // Find where start points to
        for (; (start == 0) && (*source + 1 != '\0'); start--)
            *source++;
    }
    
    // Begin copying into result
    for (; (count >= 0) && (source + 1  != '\0'); count--)
    {
        *result++ = *source++;
    }

    result = '\0';
    return localVar;
}
