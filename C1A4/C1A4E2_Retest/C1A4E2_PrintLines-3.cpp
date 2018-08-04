/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/04/2018
 * C1A4E2_PrintLines-0.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Prints out a user specified number of rows of 
 * user inputted character a user specified number of times.
 */

#include <iostream>

void PrintLines(int valueDisplayed, int valueInLine, int valueInRow)
{
    for (int rowCounter = 0; rowCounter < valueInRow; rowCounter++)
    {
        for (int lineCounter = 0; lineCounter < valueInLine; lineCounter++)
        {
            std::cout << (char)valueDisplayed;
        }
        std::cout << "\n";
    }
}