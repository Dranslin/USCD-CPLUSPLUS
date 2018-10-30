/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/27/2018
 * C2A5E2_Create2D.c
 * Win 10
 * Visual C++ 2017
 *
 * Allocates one contiguous block of memory for a 2d pointer array, 
 * and later frees that array.
 */

#include <stdio.h>
#include <stdlib.h>
#include "C2A5E2_Type-Driver.h"

Type **Create2D(size_t rows, size_t cols)
{
    // Allocate space for full array.
    Type **toArray;
    toArray = malloc(sizeof(**toArray) * (rows + (cols * rows)));
    // Test for alloc failure
    if (toArray == NULL)
    {
        fputs("Memory alloc failed.\n", stderr);
        exit(EXIT_FAILURE);
    }

    // Traverse array to point first dim array pointers to 2nd dim.
    Type **end = toArray + rows;
    for (int idx = 0; idx < rows; idx++)
        toArray[idx] = end + idx * cols;

    return(toArray);
}

// Single free call with single malloc statement used.
void Free2D(void *p)
{
    free(p);
}
