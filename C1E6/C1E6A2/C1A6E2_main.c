/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/20/2018
 * C1A6E2_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Takes two different strings that were entered by the user and 
 * uses both strcmp, and a custom version of strcmp named
 * MyStrcmp to compare the two strings lexographically.
 */

#include <stdio.h>

#define STR_LENGTH 128

int MyStrcmp(const char *s1, const char *s2);

int main(void)
{
    char bufferOne[STR_LENGTH], bufferTwo[STR_LENGTH];

    printf("Please enter a string to read.\n");
    fgets(bufferOne, STR_LENGTH, stdin);
    printf("Please enter another string to read.\n");
    fgets(bufferTwo, STR_LENGTH, stdin);

    // Removing newline character from bufferOne
    int length = (int)strlen(bufferOne);
    if (length != 0 && bufferOne[length - 1] == '\n')
        bufferOne[--length] = '\0';

    // Removing newline character from bufferTwo
    length = (int)strlen(bufferTwo);
    if (length != 0 && bufferTwo[length - 1] == '\n')
        bufferTwo[--length] = '\0';

    // Prints the result of the standard library version of strcmp
    printf("strcmp(\"%s\", \"%s\") returned %d\n", bufferOne, bufferTwo, strcmp(bufferOne, bufferTwo));
    // Prints the result of the custom version of strcmp
    printf("MyStrcmp(\"%s\", \"%s\") returned %d\n", bufferOne, bufferTwo, MyStrcmp(bufferOne, bufferTwo));

    return 0;
}
