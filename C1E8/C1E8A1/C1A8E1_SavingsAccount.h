/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 09/01/2018
 * C1A8E1_SavingsAccount.h
 * Win 10
 * Visual C++ 2017
 *
 * Provides details of the SavingsAccount class and includes inline functions
 * to calculate the account closure penalty percentage, and to display all 
 * values of the class.
 */

#ifndef C1A8E1_SAVINGSACCOUNT_H
#define C1A8E1_SAVINGSACCOUNT_H

#include <iostream>
#include <string>

const int PERCENTUPMOD = 100;

class SavingsAccount
{
private:
    int accountType;
    std::string ownerName;
    long IDnbr;
    double accountBalance, accountClosurePenaltyPercent;
public:
    void GetInitialValues();
    void DisplayValues() const;
    //Calculates closure penalty money value
    double CalculatePenalty() const
    {
        return accountBalance * accountClosurePenaltyPercent;
    }
};

// Prints all values of instance of the SavingsAccount class.
inline void SavingsAccount::DisplayValues() const
{
    std::cout << "Account type is: " << accountType << "\nOwner name is: " << ownerName <<
        "\nID number is: " << IDnbr << "\nAccount balance is: " << accountBalance <<
        "\nAccount closure penalty percent is: " << accountClosurePenaltyPercent * PERCENTUPMOD << "%\n";
}
#endif // !C1A8E1_SAVINGSACCOUNT_H
