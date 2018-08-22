/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/20/2018
 * C1A6E1_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Takes a user entered string, and then uses both the standard library
 * version of strlen and a user built variant and compares the lengths
 * put out.
 */

#include <stdio.h>

#define STR_LENGTH 128

size_t MyStrlen(const char *s1);

int main(void)
{
    char buffer[STR_LENGTH];
    printf("Please enter a string to read.\n");
    fgets(buffer, STR_LENGTH, stdin);

    // Used to remove the new line character    
    int length = (int)strlen(buffer);
    if (length != 0 && buffer[length - 1] == '\n')
        buffer[--length] = '\0';

    // Standard library use of strlen to print length of string
    printf("strlen(\"%s\") returned %i\n", buffer, (int)strlen(buffer));
    // Assignment created strlen function to print length of string
    printf("MyStrlen(\"%s\") returned %i\n", buffer, (int)MyStrlen(buffer));

    return 0;
}
