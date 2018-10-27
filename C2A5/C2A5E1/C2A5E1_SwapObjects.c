/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/27/2018
 * C2A5E1_SwapObjects.c
 * Win 10
 * Visual C++ 2017
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SwapObjects(void *pa, void *pb, size_t size)
{
    void *temp;
    if ((temp = (void *)malloc(sizeof(pa))) == NULL)
    {
        fputs("Memory alloc failed.\n", stderr);
        exit(EXIT_FAILURE);
    }
    // b -> temp, a -> b, temp -> a

    memcpy(temp, pa, size);
    memcpy(pb, pa, size);
    memcpy(pa, temp, size);

    free(temp);
/*
    void **TestA = (void ***)SafeMalloc(sizeof(size));
    void **Testb = (void ***)SafeMalloc(sizeof(size));*/
}
