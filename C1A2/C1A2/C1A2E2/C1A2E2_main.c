/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 07/22/2018
 * C1A2E2_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Simple untested lowercase to uppercase conversion.
 *
 * Takes integer input from user and creates growing slope growing
 * outward by one digit per line.
 *
 * DO NOT COPY OR RESTATE MY INSTRUCTIONS IN THE TITLE BLOCK OR ANYWHERE ELSE.
 */

#include <stdio.h>
#define DIAGONAL_CHAR '@'

int main(void)
{
    int userInput;
    int outputNumber;

    printf("Please enter any positive decimal integer value: \n");
    scanf_s("%i", &userInput);
    outputNumber = userInput;

    for (int verticalLineCount = 0; verticalLineCount < userInput; verticalLineCount++)
    {
        for (int horizontalLineCount = 0; horizontalLineCount < verticalLineCount; horizontalLineCount++)
        {
            printf("%d", outputNumber % 10);
            outputNumber++;
        }
        printf("%c\n", DIAGONAL_CHAR);
    }

    return 0;
}