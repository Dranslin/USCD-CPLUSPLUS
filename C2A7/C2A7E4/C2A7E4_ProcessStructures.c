/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/9/2018
 * C2A7E4_ProcessStructures.c
 * Win 10
 * Visual C++ 2017
 *
 * 
 */


#include "C2A7E4_Test-Driver.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128

void *ReverseEndian(void *ptr, size_t size);

struct Test *ReverseMembersEndian(struct Test *ptr)
{
    ReverseEndian((void *)&ptr->dbl, sizeof(ptr->dbl));
    ReverseEndian((void *)&ptr->flt, sizeof(ptr->flt));
    ReverseEndian((void *)&ptr->vp, sizeof(ptr->vp));
    return (ptr);
}

struct Test *ReadStructures(struct Test *ptr, size_t count, FILE *fp)
{
    size_t returnVal = fread(ptr, sizeof(ptr), count, fp);
    if (returnVal != count)
    {
        // Fail condition: Alert and exit program.
        fprintf(stderr, "Temp file failed to open.");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

struct Test *WriteStructures(const struct Test *ptr, size_t count, FILE *fp)
{
    size_t returnVal = fwrite(&ptr, sizeof(ptr), count, fp);
    if (returnVal != count)
    {
        // Fail condition: Alert and exit program.
        fprintf(stderr, "Temp file failed to open.");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}
