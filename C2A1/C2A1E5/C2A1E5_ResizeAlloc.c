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
* 
*/

#include <stdio.h>
#include <stdlib.h>

void *ResizeAlloc(void *pOld, size_t newSize, size_t oldSize)
{
    char *newblock;
    if (newSize == 0)
    {
        return NULL;
    }
    else
    {
        if (newBlock = (char *)malloc(newSize * sizeof(char)) == NULL)
        {
            return NULL;
        }
        else if (pOld == NULL)
        {
            return newBlock;
        }
        else
        {
            if (newSize > oldSize)
            {

            }
            else
            {

            }
            free(pOld);
        }

        int *newLoc = malloc(newSize);
    }
}