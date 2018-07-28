/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 07/28/2018
 * C1A3E2_main.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Prints user input number in reverse.
 */

#include <iostream>

using std::cin;
using std::cout;

const int MOD_CHK = 10;

int main()
{
    int userInt;
    
    cout << "Please enter a integer value to be reversed.\n";
    cin >> userInt;
    cout << "\"" << userInt << "\" in reverse is \"";

    // Check if input is a single digit.
    if (userInt / MOD_CHK == 0)
    {
        userInt >= 0 ? cout << userInt << "\"\n" : cout << -userInt << "-\"\n";
    }
    else
    {
        // When not a single digit, keep running.
        while ((userInt / MOD_CHK) != 0)
        {
            userInt % MOD_CHK > 0 ? cout << userInt % MOD_CHK : cout << -(userInt % MOD_CHK);
            userInt /= MOD_CHK;
            // If single digit left, print last character and if needed, sign.
            if (userInt / MOD_CHK == 0)
            {
                userInt >= 0 ? cout << userInt << "\"\n" : cout << -userInt << "-\"\n";
            }
        }
    }

    return 0;
}
