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
 * Does the same as C1A4E2, but with the multi-line style using 
 * default values listed below.
 */

#include <iostream>

const int CYCLES = 5;
const int DEFAULTLINES = 1;
const int CHARROWS = 1;
const char DEFAULTCHAR = 'Z';
using std::cout;
using std::cin;

void PrintLines(int userCharacter = DEFAULTCHAR, int charOnLine = DEFAULTLINES, int charRows = CHARROWS);

int main()
{
    for (int iterations = 0; iterations < CYCLES; iterations++)
    {
        char userCharacter;
        int charOnLine;
        int charRows;

        cout << "Please enter a character to display, the number of times to display "
            "the character, and the number of lines to show:\n";
        cin >> userCharacter >> charOnLine >> charRows;

        // Below functions prints a certain number of rows of a character a certain number of times.
        // No auto default.
        PrintLines(userCharacter, charOnLine, charRows);
        // Auto default to two lines.
        PrintLines(userCharacter, charOnLine);
        // Auto default to two lines and five chars per line.
        PrintLines(userCharacter);
        // Auto defaults to two lines, five chars per line and character C printed.
        PrintLines();
    }
    return 0;
}
