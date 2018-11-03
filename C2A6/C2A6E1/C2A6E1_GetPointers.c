/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/3/2018
 * C2A6E1_GetPointers.c
 * Win 10
 * Visual C++ 2017
 *
 * Returns pointers to the printf and puts functions
 */

#include <stdio.h>

int (*GetPrintfPointer(void))(const char *format, ...)
{
    int (*pPrintf)(const char *format, ...) = printf;
    return pPrintf;
}

int (*GetPutsPointer(void))(const char *str)
{
    int (*pPuts)(const char *str) = puts;
    return pPuts;
}
