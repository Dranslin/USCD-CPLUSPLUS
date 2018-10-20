/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/12/2018
 * C2A3E4_OpenFile.c
 * Win 10
 * Visual C++ 2017
 *
 * Opens the file who's name is specified in filename, or errors out
 * and terminates the program.
 */

#include <stdio.h>
#include <stdlib.h>


FILE *OpenFile(const char *fileName)
{
    FILE *source;

    if ((source = fopen(fileName, "r")) == NULL)
    {
        // Fail condition: Alert and exit program.
        fprintf(stderr, "File %s failed to open.", fileName);
        exit(EXIT_FAILURE);
    }
    return source;
}
