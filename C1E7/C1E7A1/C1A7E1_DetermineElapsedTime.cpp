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
    long startTimeConvert = startTime->hours * MINUTESECONDMOD * MINUTESECONDMOD +
        startTime->minutes * MINUTESECONDMOD + startTime->seconds;
    long endTimeConvert = endTime->hours * MINUTESECONDMOD * MINUTESECONDMOD +
        endTime->minutes * MINUTESECONDMOD + endTime->seconds;

    // If times are the same, or if the total start time is larger than the end time
    // then set 24 hours worth of difference.
    if ((startTime->hours == endTime->hours) && 
        (startTime->minutes == endTime->minutes) && 
        (startTime->seconds == endTime->seconds) ||
        (startTimeConvert > endTimeConvert))
    {
        resultTime.hours = DAY;
    }

    // Check if start time seconds larger than end time seconds
    // If so, pull one minute worth, then calculate seconds difference.
    if (endTime->seconds < startTime->seconds) //
    {
        resultTime.minutes--;
        resultTime.seconds += MINUTESECONDMOD;
    }
    resultTime.seconds += endTime->seconds - startTime->seconds;

    // Check if start time minutes larger than end time minutes
    // If so, pull one hour worth, then calculate minutes difference.
    if (endTime->minutes + resultTime.minutes < startTime->minutes)
    {
        resultTime.hours--;
        resultTime.minutes += MINUTESECONDMOD;
    }
    resultTime.minutes += endTime->minutes - startTime->minutes;
        
    // Check if start time hours is larger than end time hours
    // If so, pull one day's worth of hours, then computer difference.
    if (endTime->hours + resultTime.hours < startTime->hours)
    {
        resultTime.hours += DAY;
    }
    resultTime.hours += endTime->hours - startTime->hours;


    return &resultTime;
}
