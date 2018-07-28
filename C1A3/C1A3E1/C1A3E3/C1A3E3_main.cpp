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
const int MAX = 15;

int main()
{
    int userHex;
    int divisorValue = 1; // bottom

    cout << "Please write a number in hexidecimal.\n";
    cin >> hex >> userHex;

    if (userHex < 0)
    {
        cout << "\"-" << hex << -userHex << "\" in words is \"";
    }
    else
    {
        cout << "\"" << hex << userHex << "\" in words is \"";
    }

    // if negitive, print minus and convert to positive
    if (userHex < 0)
    {
        cout << "minus";
        userHex = -userHex;
    }

    if (userHex > MAX)
    {
        for (int dividendValueLoop = userHex; dividendValueLoop > MAX; dividendValueLoop /= DIVISOR)
        {
            divisorValue *= DIVISOR;
        }

        int dividendValue = userHex;
        int mostSigDigit;
        do
        {
            mostSigDigit = dividendValue / divisorValue;
            printWord(mostSigDigit);

            dividendValue -= mostSigDigit * divisorValue;
            divisorValue /= DIVISOR;
        } while (divisorValue != 0);
    }
    else
    {
        printWord(userHex);
    }

    cout << "\"\n";

    return 0;
}


void printWord(int testInt)
{
    switch (testInt)
    {
        case 1:
            cout << " one";
            break;
        case 2:
            cout << " two";
            break;
        case 3:
            cout << " three";
            break;
        case 4:
            cout << " four";
            break;
        case 5:
            cout << " five";
            break;
        case 6:
            cout << " six";
            break;
        case 7:
            cout << " seven";
            break;
        case 8:
            cout << " eight";
            break;
        case 9:
            cout << " nine";
            break;
        case 10:
            cout << " A";
            break;
        case 11:
            cout << " B";
            break;
        case 12:
            cout << " C";
            break;
        case 13:
            cout << " D";
            break;
        case 14:
            cout << " E";
            break;
        case 15:
            cout << " F";
            break;
        case 0:
            cout << " Zero";
            break;
    }
}
