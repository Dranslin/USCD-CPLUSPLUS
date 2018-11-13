/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/9/2018
 * C2A7E4_ReverseEndian.c
 * Win 10
 * Visual C++ 2017
 *
 * Swaps endian style from big to little and vice versa by
 * walking "in" from the address end.
 */

#include <stdio.h>

void *ReverseEndian(void *ptr, size_t size)
{
    // Get beginning and end of the object.
    char *head = (char *)ptr;
    char *tail = head + size - 1;

    // Start swapping from beginning to end, moving one address "in"
    // for each address.
    for (; tail > head; --tail, ++head)
    {
        char temp = *head;
        *head = *tail;
        *tail = temp;
    }

    return (ptr);
}
