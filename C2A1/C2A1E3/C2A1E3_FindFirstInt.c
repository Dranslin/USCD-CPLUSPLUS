/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 09/29/2018
 * C2A1E3_FindFirstInt.c
 * Win 10
 * Visual C++ 2017
 *
 * Searches an array of integers for the first occurance of the value argument
 * and returns a pointers to that address, otherwise returns a null pointer.
 */

#include <stdio.h>

int *FindFirstInt(const int *ptr, size_t count, int value)
{
    int returnIndex = 0;
    // Go through either whole array or until match is found.
    while ((ptr[returnIndex] != value) && (returnIndex < (int)count))
        returnIndex++;
    // if no match returnIndex is greater or equal to count
    return (returnIndex >= (int)count) ? NULL : &ptr[returnIndex];
}
