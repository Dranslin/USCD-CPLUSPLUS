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
 * Swaps the contents of pa and pb
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SwapObjects(void *pa, void *pb, size_t size)
{
    void *temp = malloc(size);
    // Test for failure
    if (temp == NULL)
    {
        fputs("Memory alloc failed.\n", stderr);
        exit(EXIT_FAILURE);
    }

    // b -> temp, a -> b, temp -> a
    memcpy((void *)temp, (void *)pa, size);
    memcpy((void *)pa, (void *)pb, size);
    memcpy((void *)pb, (void *)temp, size);
    free(temp);
}
