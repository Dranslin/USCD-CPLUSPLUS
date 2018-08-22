/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/20/2018
 * C1A6E3_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Extracts and prints substring taken from source string.
 */

#define MAX_STRING_SIZE 256

#include <stdio.h>

char *GetSubstring(const char source[], int start, int count, char result[]);

int main(void)
{
    char source[MAX_STRING_SIZE] = ""; // Deals w/ garbage values after fill
    char results[MAX_STRING_SIZE] = ""; // Deals w/ garbage values after fill
    int startIndex, count;

    printf("Please enter a sequence of characters to act as the original string.\n");
    fgets(source, MAX_STRING_SIZE, stdin);
    printf("Please enter an index to begin at, a space, and then "
        "the number of chars after to extract.\n");
    scanf("%d%d", &startIndex, &count);

    // Used to remove newline character from source
    int length = (int)strlen(source);
    if (length != 0 && source[length - 1] == '\n')
        source[--length] = '\0';

    // Prints source string, starting point, counter, and the extracted result.
    printf("\n\"%s\", %d, %d extracts \"%s\"", 
        source, startIndex, count, GetSubstring(source, startIndex, count, results));

    return 0;
}
