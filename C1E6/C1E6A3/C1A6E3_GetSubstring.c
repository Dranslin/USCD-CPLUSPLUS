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
 * substring. This accounts for negative starting value or zero value
 * and if going beyond full string, ends the process and returns what
 * was copied.
 */

char *GetSubstring(const char source[], int start, int count, char result[])
{
    char *localVar = result;

    if (start > 0) // Skip if 0 so that first letter isn't lost
    {
        // Find where start points to
        for (; (start > 0) && *source++; start--)
            ;
    }
    
    // Begin copying into result
    for (; (count > 0) && (*result++ = *source++); count--)
        ;
    return localVar;
}
