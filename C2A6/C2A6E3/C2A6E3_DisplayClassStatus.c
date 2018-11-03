/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/3/2018
 * C2A6E3_DisplayClassStatus.c
 * Win 10
 * Visual C++ 2017
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Compare(const void *elemA, const void *elemB)
{
    return strcmp((char *)elemB, (char *)elemA);
}

void SortStudents(const char *studentList[], size_t studentCount)
{
    qsort(studentList, studentCount, sizeof(studentList[0]), Compare);
}

void DisplayClassStatus(const char *registrants[], size_t registrantCount, 
    const char *attendees[], size_t attendeeCount)
{
    printf("Not present:\n");
    for (int idx = 0; idx < registrantCount; idx++)
    {
        bsearch(registrants[idx], attendees, attendeeCount, sizeof(attendees[0]), Compare);
    }


    printf("Not registered:\n");
    for (int idx = 0; idx < attendeeCount; idx++)
    {
        bsearch(attendees[idx], registrants, registrantCount, sizeof(registrants[0]), Compare);
    }
}
