/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/3/2018
 * C2A6E4_OpenFile.c
 * Win 10
 * Visual C++ 2017
 *
 * Opens specified file or errors out.
 */

#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
    FILE *source = NULL;

    // If file fails to open, terminate program
    if ((source = fopen(fileName, "r")) == NULL)
    {
        // Fail condition: Alert and exit program.
        fprintf(stderr, "File %s failed to open.", fileName);
        exit(EXIT_FAILURE);
    }
    return source;
}