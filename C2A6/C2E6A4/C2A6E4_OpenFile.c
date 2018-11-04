/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/3/2018
 * C2A6E3_DisplayClassStatus.c
 * Win 10
 * Visual C++ 2017
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
    FILE *source = NULL;

    if ((source = fopen(fileName, "r")) == NULL)
    {
        // Fail condition: Alert and exit program.
        fprintf(stderr, "File %s failed to open.", fileName);
        exit(EXIT_FAILURE);
    }
    return source;
}