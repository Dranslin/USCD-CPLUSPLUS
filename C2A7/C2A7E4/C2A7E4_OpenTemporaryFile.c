/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/9/2018
 * C2A7E3_ReverseEndian.c
 * Win 10
 * Visual C++ 2017
 *
 * 
 */

#include <fstream>
#include <stdio.h>

FILE *OpenTemporaryFile(void)
{
    FILE tempFile = tmpfile();
    if (tempFile == NULL)
    {
        // Fail condition: Alert and exit program.
        fprintf(stderr, "Temp file failed to open.\n");
        exit(EXIT_FAILURE);
    }
}
