/*
* Nicholas Patience U07985691
* Nickspatience@gmail.com
* C/C++ Programming I : Fundamental Programming Concepts
* 132297 Ray Mitchell
* 08/04/2018
* C1A4E3_PrintLines.cpp
* Win 10
* Visual C++ 2017
*
* Computes minimum value of two.
*/

void printLines(int valueDisplayed, int valueInLine, int valueInRow)
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