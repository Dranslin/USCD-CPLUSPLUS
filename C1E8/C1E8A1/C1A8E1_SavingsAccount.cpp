/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 09/01/2018
 * C1A8E1_SavingsAccount.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Provides the definition for the method that initializes values
 * for any new instances of a SavingsAccount class.
 */

#include "C1A8E1_SavingsAccount.h"

const double PERCENTAGEMOD = 0.01;

void SavingsAccount::GetInitialValues()
{
    std::cout << "Please enter an integer value for the account type:\n";
    std::cin >> accountType;
    std::cout << "Please enter a string value for the owner name:\n";
    std::cin >> std::ws;
    std::getline(std::cin, ownerName);
    std::cout << "Please enter a long integer value for the account ID:\n";
    std::cin >> IDnbr;
    std::cout << "Please enter a value for the account balance:\n";
    std::cin >> accountBalance;
    std::cout << "Please enter a value for the account closure penalty percent:\n";
    std::cin >> accountClosurePenaltyPercent;

    if (accountClosurePenaltyPercent >= 1)      // If not entered as a percentage value
    {
        // Convert to a proper percentage
        accountClosurePenaltyPercent *= PERCENTAGEMOD;
    }    
}
