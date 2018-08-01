/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 07/28/2018
 * C1A3E3_main.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Converts hex entries into the word equivalent
 */

#include <iostream>

using std::cout;
using std::cin;
using std::hex;

void printWord(int testInt);

const int DIVISOR = 16;
const int MAX = DIVISOR - 1;

int main() // Input hex from user and print out word equivalent
{
    int userInput;
    int divisorValue = 1; // bottom

    cout << "Please write a number in hexadecimal.\n";
    cin >> hex;
    cout << hex;

    cin >> userInput;

    if (userInput < 0)
    {
        cout << "\"-" << -userInput << "\" in words is \"";
    }
    else
    {
        cout << "\"" << userInput << "\" in words is \"";
    }

    // if negative, print minus and convert to positive
    if (userInput < 0)
    {
        cout << "minus ";
        userInput = -userInput;
    }

    // Algorithim for extracting most significant digit from 16-bit.
    if (userInput > MAX)
    {
        for (int dividendValueLoop = userInput; dividendValueLoop > MAX; dividendValueLoop /= DIVISOR)
        {
            divisorValue *= DIVISOR;
        }

        int dividendValue = userInput;
        do
        {
            int mostSigDigit;
            mostSigDigit = dividendValue / divisorValue;
            printWord(mostSigDigit); // switch statement prints word

            dividendValue -= mostSigDigit * divisorValue;
            divisorValue /= DIVISOR;
        } while (divisorValue != 0);
    }
    else
    {
        printWord(userInput);
    }

    cout << "\"\n";

    return 0;
}

// Function used to encapsulate the switch statement that prints the word
void printWord(int testInt)
{
    switch (testInt)
    {
        case 1:
            cout << "one ";
            break;
        case 2:
            cout << "two ";
            break;
        case 3:
            cout << "three ";
            break;
        case 4:
            cout << "four ";
            break;
        case 5:
            cout << "five ";
            break;
        case 6:
            cout << "six ";
            break;
        case 7:
            cout << "seven ";
            break;
        case 8:
            cout << "eight ";
            break;
        case 9:
            cout << "nine ";
            break;
        case 10:
            cout << "A ";
            break;
        case 11:
            cout << "B ";
            break;
        case 12:
            cout << "C ";
            break;
        case 13:
            cout << "D ";
            break;
        case 14:
            cout << "E ";
            break;
        case 15:
            cout << "F ";
            break;
        case 0:
            cout << "Zero ";
            break;
    }
}
