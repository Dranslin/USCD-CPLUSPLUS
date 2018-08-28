/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/23/2018
 * C1A7E1_DetermineElapsedTime.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Takes in two constant pointers to a MyTime structure which have
 * integers for hours, minutes, and seconds. These are the start
 * time and ending time to be calculated with. This function takes
 * the difference between the starting time and the ending time,
 * then returns a pointers to a new constructed MyTime struct.
 */

#include "C1A7E1_MyTime.h"
const int DAY = 24;
const int MINUTESECONDMOD = 60;

MyTime *DetermineElapsedTime(const MyTime *startTime, const MyTime *endTime)
{
    static MyTime resultTime = {0, 0, 0};

    // If times are the same, then set 24 hours worth of difference.
    if ((startTime->hours == endTime->hours) && 
        (startTime->minutes == endTime->minutes) && 
        (startTime->seconds == endTime->seconds))
    {
        resultTime.hours = DAY;
        resultTime.minutes = 0;
        resultTime.seconds = 0;
    }
    else
    {
        // Check if end time seconds larger than start time seconds
        // If so, pull one minute worth, then calculate seconds difference.
        if (startTime->seconds < endTime->seconds)
        {
            resultTime.minutes--;
            resultTime.seconds += MINUTESECONDMOD;
        }
        resultTime.seconds += startTime->seconds - endTime->seconds;

        // Check if end time minutes larger than start time minutes
        // If so, pull one hour worth, then calculate minutes difference.
        if (startTime->minutes + resultTime.minutes < endTime->minutes)
        {
            resultTime.hours--;
            resultTime.minutes += MINUTESECONDMOD;
        }
        resultTime.minutes += startTime->minutes - endTime->minutes;
        
        // Check if end time hours is larger than start time hours
        // If so, pull one day's worth of hours, then computer difference.
        if (startTime->hours + resultTime.hours < endTime->hours)
        {
            resultTime.hours += DAY;
        }
        resultTime.hours += startTime->hours - endTime->hours;
    }

    return &resultTime;
}
