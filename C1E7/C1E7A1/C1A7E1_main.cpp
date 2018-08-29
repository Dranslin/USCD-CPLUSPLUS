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
const int STARTRUN = 0;
const int ENDRUN = 3;

using std::cout;
using std::cin;
using std::setfill;
using std::setw;

int main()
{
    // Run whole process ENDRUN number of times.
    cout << setfill('0');
    for (int timesRun = STARTRUN; timesRun < ENDRUN; timesRun++)
    {
        // utr holds time difference struct
        MyTime userTimeOne, userTimeTwo, *utr; 
        char delimOne, delimTwo;

        cout << "Enter two times in HH:MM:SS format, separated by a space.\n";
        cin >> userTimeOne.hours >> delimOne >> userTimeOne.minutes >> delimTwo >>
            userTimeOne.seconds >> userTimeTwo.hours >> delimOne >>
            userTimeTwo.minutes >> delimTwo >> userTimeTwo.seconds;

        // Get difference in time
        utr = DetermineElapsedTime(&userTimeOne, &userTimeTwo); 

        cout << "The time elapsed from " << setw(2) << userTimeOne.hours <<
            delimOne << setw(2) << userTimeOne.minutes << delimTwo << setw(2) << 
            userTimeOne.seconds << " to " << setw(2) << userTimeTwo.hours << delimOne 
            << setw(2) << userTimeTwo.minutes << delimTwo << setw(2) << 
            userTimeTwo.seconds << " is " << setw(2) << utr->hours << delimOne 
            << setw(2) << utr->minutes << delimTwo << setw(2) << utr->seconds << "\n";
    }
    return 0;
}
