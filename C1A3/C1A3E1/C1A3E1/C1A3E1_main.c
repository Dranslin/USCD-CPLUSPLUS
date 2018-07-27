/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 07/27/2018
 * C1A3E1_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Computes the sum of cubes up to the provided user input number.
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int userInputNumber;
    short total = 0;

    do
    {
        printf("Please enter a positive value that is either zero, or greater than zero.\n");
        scanf_s("\n%i", &userInputNumber);
        printf("User has entered: %d\n", userInputNumber);
    }
    while (!(userInputNumber >= 0));

    printf("nbr    cubic sum\n");
    printf("_________________\n");
    for (int currentSquare = 0; currentSquare <= userInputNumber; currentSquare++)
    {
        total += currentSquare * currentSquare * currentSquare;
        printf("%-3d    %-10d\n", currentSquare, total);
    }

    return 0;
}
