/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 09/29/2018
 * C2A1E2_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Prints out a count of the command line arguments provided
 * as well as the arguments themselves
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Number of command line arguments are: %d\n", argc);
    for (int index = 0; index < argc; index++)
        printf("%s\n", argv[index]);
    return 0;
}
