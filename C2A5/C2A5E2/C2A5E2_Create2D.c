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
    size_t rowBitSize = sizeof(Type *) * rows;
    Type **toArray;

    // Allocate space for full array.
    toArray = malloc(rows * sizeof *toArray + (rows * (cols * sizeof **toArray)));
    //toArray = (Type **)malloc(rowBitSize + rowBitSize * cols);
    if (toArray == NULL)
    {
        fputs("Memory alloc failed.\n", stderr);
        exit(EXIT_FAILURE);
    }
    size_t i;
    int * const data = toArray + rows;
    for (i = 0; i < rows; i++)
        toArray[i] = data + i * cols;

    //Type **traveler = toArray;
    //int *end = toArray + rows;
    //for (int idx = 0; idx < rows; ++idx)
    //    toArray[idx] = toArray + idx * (int)cols;


    // Traverse array to place row pointers
    //int *data = toArray + rows;
    //for (size_t i = 0; i < rows; i++)
    //    toArray[i] = data + i * cols;

    return(toArray);
}

void Free2D(void *p)
{
    free(p);
}
