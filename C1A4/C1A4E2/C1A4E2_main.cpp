/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/04/2018
 * C1A4E2_main.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Computes minimum value of two.
 */

#include <iostream>
#include "C1A4E2_PrintLines-0.h"
#include "C1A4E2_PrintLines-1.h"
#include "C1A4E2_PrintLines-2.h"
#include "C1A4E2_PrintLines-3.h"

const int CYCLES = 5;

using std::cout;
using std::cin;

int main()
{
    char userCharacter;
    int charOnLine;
    int charRows;

    for (int iterations = 0; iterations < CYCLES; iterations++)
    {
        cout << "Please enter a character to display, the number of times to display "
            "the character, and the number of lines to show:\n";
        cin >> userCharacter >> charOnLine >> charRows;
        //cout << "User character: " << userCharacter << " Chars per line: " << 
        //charOnLine << " Char Rows: " << charRows << "\n//std::

        //cout << "Rows\n//std::
        PrintLines(userCharacter, charOnLine, charRows);
        //cout << "Lines\n//std::
        PrintLines(userCharacter, charOnLine);
        //cout << "Single\n//std::
        PrintLines(userCharacter);
        //cout << "Char\n//std::
        PrintLines();
    }
    return 0;
}
