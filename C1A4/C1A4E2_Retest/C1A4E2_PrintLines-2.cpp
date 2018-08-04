/*
* Nicholas Patience U07985691
* Nickspatience@gmail.com
* C/C++ Programming I : Fundamental Programming Concepts
* 132297 Ray Mitchell
* 08/04/2018
* C1A4E2_PrintLines-2.cpp
* Win 10
* Visual C++ 2017
*
* Prints out row of user inputed character a user specified number of times.
*/

#include <iostream>

void PrintLines(int valueDisplayed, int valueInLine)
{
    for (int lineCounter = 0; lineCounter < valueInLine; lineCounter++)
    {
        std::cout << (char)valueDisplayed;
    }
    std::cout << "\n";
}
