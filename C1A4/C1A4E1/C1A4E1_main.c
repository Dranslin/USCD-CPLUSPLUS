/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/04/2018
 * C1A4E1_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Main driver. Takes double inputs and computes max and min between them.
 */

#include <stdio.h>
#include "C1A4E1_ComputeMaximum.h"
#include "C1A4E1_ComputeMinimum.h"

int main(void)
{
    double userA = 0;
    double userB = 0.0f;

    printf("Please enter any decimal numeric value separated by spaces.\n");
    scanf("\n%lf %lf", &userA, &userB);

    printf("ComputeMinimum(%lf, %lf) returned %lf\n", userA, userB, ComputeMinimum(userA, userB));
    printf("ComputeMaximum(%lf, %lf) returned %lf\n", userA, userB, ComputeMaximum(userA, userB));

    return 0;
}
