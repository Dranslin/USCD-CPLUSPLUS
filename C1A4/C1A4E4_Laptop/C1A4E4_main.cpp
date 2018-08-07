/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/04/2018
 * C1A4E4_main.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Uses macros and inline functions from header to print out
 * the maximum of three different entered values
 */

#include <iostream>
#include "C1A4E4_MaxOf.h"

using std::cout;
using std::cin;

int main()
{
    long double value1, value2, value3;

    cout << "Please enter three values separated by spaces:\n";
    cin >> value1 >> value2 >> value3;

    cout << "mMaxOf3(" << value1 << ", " << value2 << ", " << value3 <<
        ") returned " << mMaxOf3(value1, value2, value3) << "\n";
    cout << "fMaxOf3(" << value1 << ", " << value2 << ", " << value3 <<
        ") returned " << fMaxOf3(value1, value2, value3) << "\n";

    return 0;
}
