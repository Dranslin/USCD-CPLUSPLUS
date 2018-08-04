/*
* Nicholas Patience U07985691
* Nickspatience@gmail.com
* C/C++ Programming I : Fundamental Programming Concepts
* 132297 Ray Mitchell
* 08/04/2018
* C1A4E3_main.cpp
* Win 10
* Visual C++ 2017
*
* Computes minimum value of two.
*/

#include <iostream>
#include "C1A4E3_PrintLines.h"

const int CYCLES = 5;

using std::cout;
using std::cin;

void printLines(int valueDisplayed, int valueInLine, int valueInRow)

int main()
{
    char userCharacter;
    int charOnLine;
    int charRows;

    for (int iterations = 0; iterations < CYCLES; iterations++)
    {
        cout << "Please enter a character to display, the number of times to display "
            << "the character, and the number of lines to show:\n";
        cin >> userCharacter >> charOnLine >> charRows;
        //cout << "User character: " << userCharacter << " Chars per line: " << charOnLine << " Char Rows: " << charRows << "\n";

        //cout << "Rows\n";
        printLines(userCharacter, charOnLine, charRows);
        //cout << "Lines\n";
        printLines(userCharacter, charOnLine);
        //cout << "Single\n";
        printLines(userCharacter);
        //cout << "Char\n";
        printLines();
    }
    return 0;
}
