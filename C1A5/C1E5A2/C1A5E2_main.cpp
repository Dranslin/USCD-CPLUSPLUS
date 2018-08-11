/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/11/2018
 * C1A5E2_main.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Prints results of ComputeMinimum and ComputeMaximum using references.
 */

#include <iostream>

using std::cout;
using std::cin;

double &ComputeMaximum(const double &valueOne, const double &valueTwo);
double &ComputeMinimum(const double &valueOne, const double &valueTwo);

int main()
{
    double userValueOne, userValueTwo;

    cout << "Please enter any decimal numeric value separated by spaces.\n";
    cin >> userValueOne >> userValueTwo;

    // Print result of Minimum function
    cout << "ComputeMinimum(" << userValueOne << ", " << userValueTwo << ") returned " 
        << ComputeMinimum(userValueOne, userValueTwo) << "\n";
    // Print result of Maximum function
    cout << "ComputeMaximum(" << userValueOne << ", " << userValueTwo << ") returned " 
        << ComputeMaximum(userValueOne, userValueTwo) << "\n";

    return 0;
}
