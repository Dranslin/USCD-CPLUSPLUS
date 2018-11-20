/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/17/2018
 * C2A8E2_DisplayModifiedSingleReals.c
 * Win 10
 * Visual C++ 2017
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define BYTES_READ 4

void DisplayModifiedSingleReals(FILE *inFile)
{
    unsigned char buffer[BYTES_READ];

    while (fread(buffer, sizeof(*buffer), BYTES_READ, inFile) == BYTES_READ)
    {
        printf("%s", buffer);
    }

}
