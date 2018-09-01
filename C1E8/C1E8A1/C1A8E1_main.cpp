/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 09/01/2018
 * C1A8E1_main.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Initializes an instance of the SavingsAccount class named userAccount. This then
 *  calls the member function to fill the class with values, displays all values, 
 * then calls the function to calculate the closure penalty to display in std out.
 */

#include "C1A8E1_SavingsAccount.h"
#include <iostream>

using std::cout;
using std::cin;

int main()
{
    SavingsAccount userAccount;         // Creates instance of SavingsAccount class
    userAccount.GetInitialValues();     // Initializes values for userAccount instance
    userAccount.DisplayValues();        // Displays values for userAccount instance
    // Shows closure penalty
    cout << "Account closure penalty is: " << userAccount.CalculatePenalty() << "\n";

    return 0;
}
