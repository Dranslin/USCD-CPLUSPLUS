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

extern double ComputeMaximum(double varA, double varB); // Returns max of two var
extern double ComputeMinimum(double varA, double varB); // Returns min of two var

int main(void)
{
    double userA, userB;

    printf("Please enter any decimal numeric value separated by spaces.\n");
    scanf("%f %f", &userA, &userB);

    //Print minimum of two variables
    printf("ComputeMinimum(%f, %f) returned %f\n", userA, userB, ComputeMinimum(userA, userB));
    //Print maximum of two variables
    printf("ComputeMaximum(%f, %f) returned %f\n", userA, userB, ComputeMaximum(userA, userB));

    return 0;
}
