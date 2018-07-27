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

int main(void)
{
    int userInputNumber;
    short total = 0;

    printf("Please enter a positive value that is either zero, or greater than zero.\n");
    scanf("%i", &userInputNumber);
    printf("User has entered: %d\n", userInputNumber);

    printf("nbr cubic sum\n_________________\n");
    //Begin cube calculation and printing
    for (int currentCube = 0; currentCube <= userInputNumber; currentCube++)
    {
        total += (short)(currentCube * currentCube * currentCube);
        printf("%-3d %10d\n", currentCube, total);
    }

    return 0;
}
