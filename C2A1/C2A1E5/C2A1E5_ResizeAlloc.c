/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 09/29/2018
 * C2A1E5_ResizeAlloc.c
 * Win 10
 * Visual C++ 2017
 *
 * Allocates just enough memory space to copy the contents of pOld
 * to a new space, returning a null pointer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ResizeAlloc(void *pOld, size_t newSize, size_t oldSize)
{
    char *newblock = NULL;
    // Fail condition: Zero new size.
    if (newSize == 0)
    {
        return NULL;
    }
    // Success: Begin space allocation.
    else
    {
        // Fail condition: Space allocation failed.
        if ((newblock = (char *)malloc(newSize * sizeof(char))) == NULL)
        {
            return NULL;
        }
        // Passable condition: Nothing to copy, just move to new allocation.
        else if (pOld == NULL)
        {
            return newblock;
        }
        // Success condition: begin copying.
        else
        {
            if (newSize > oldSize)
            {
                memcpy(newblock, pOld, oldSize);
            }
            else
            {
                memcpy(newblock, pOld, newSize);
            }
        }
        free(pOld);
    }
    return newblock;
}
