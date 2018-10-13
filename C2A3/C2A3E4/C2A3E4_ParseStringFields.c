/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/12/2018
 * C2A3E4_ParseStringFields.c
 * Win 10
 * Visual C++ 2017
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERLENGTH 256

void ParseStringFields(FILE *fp)
{
    char *buffer[BUFFERLENGTH];
    char delimList[] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u', '\t', '\n' };
    fgets(buffer, BUFFERLENGTH, fp);
    printf("%s\n", buffer);

    char *subString = strtok(buffer, delimList);
    while (subString != NULL)
    {
        printf("%s\n", subString);
        subString = strtok(subString, delimList);
    }


}