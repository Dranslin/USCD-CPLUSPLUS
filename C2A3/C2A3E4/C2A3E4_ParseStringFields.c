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
 * Reads contents specified in fp line by line and separates
 * the line into substrings based off of the criteria below. 
 * These substrings are then printed out line-by-line.
 * 
 * Criteria: 
 * 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u', '\t', '\n'
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFERLENGTH 256

void ParseStringFields(FILE *fp)
{
    char *buffer[BUFFERLENGTH];
    
    // Read through file line-by-line
    while (fgets(buffer, BUFFERLENGTH, fp))
    {
        char *subString = strtok(buffer, "AEIOUaeiou\t\n");
        // Proceed through substrings
        while (subString != NULL)
        {
            // Ignore leading whitespace
            while (isspace(*subString))
            {
                subString++;
            }

            printf("%s\n", subString);
            // Get next substring token
            subString = strtok(NULL, "AEIOUaeiou\t\n");
        }
    }
}
