/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/23/2018
 * C1A7E1_main.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Prompts the user to enter two times in HH:MM:SS format then calls
 * DetermineEllapsedTime() to calculate the difference between the
 * two times and return it as a pointer to a new struct. Same
 * start and ending times are treated as 24 hours.
 */

#include <iostream>
#include <iomanip>
#include "C1A7E1_MyTime.h"

MyTime *DetermineElapsedTime(const MyTime *startTime, const MyTime *endTime);

using std::cout;
using std::cin;
using std::setfill;
using std::setw;

int main()
{
    MyTime userTimeOne, userTimeTwo, *utr;
    char delimOne, delimTwo;

    cout << "Enter two times in HH:MM:SS format, separated by a space.\n";
    cin >> userTimeOne.hours >> delimOne >> userTimeOne.minutes >> delimTwo >>
        userTimeOne.seconds >> userTimeTwo.hours >> delimOne >>
        userTimeTwo.minutes >> delimTwo >> userTimeTwo.seconds;

    utr = DetermineElapsedTime(&userTimeOne, &userTimeTwo);

    cout << setfill('0') << setw(2) << "The time elapsed from " << userTimeOne.hours <<
        delimOne << userTimeOne.minutes << delimTwo << userTimeOne.seconds << " to " 
        << userTimeTwo.hours << delimOne << userTimeTwo.minutes << delimTwo << 
        userTimeTwo.seconds << " is " << utr->hours << delimOne << utr->minutes << 
        delimTwo << utr->seconds << "\n";

    return 0;
}
