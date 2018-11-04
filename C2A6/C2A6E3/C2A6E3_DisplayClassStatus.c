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
 * Compare is used to call strcmp to compare the two arguments to test for
 * a match. This function is used in the bsearch function in both
 * SortStudents and DisplayClassStatus.
 *
 * Sort simply calls qsort on the target array and uses the compare function.
 *
 * DisplayClassStatus searches through the two provided arrays and 
 * prints out the names that display in one array, and not the other.
 * This gives a list of individuals that registered but did not attend,
 * and a list for those that attended but did not register.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calls strcmp and uses return value for both sorting and matching.
int Compare(const void *elemA, const void *elemB)
{
    return strcmp(*(char **)elemA, *(char **)elemB);
}

// Uses Compare, and thus strcmp to sort the array
void SortStudents(const char *studentList[], size_t studentCount)
{
    qsort(studentList, studentCount, sizeof(studentList[0]), Compare);
}

// Prints results for those on reg list but not attend and vice versa
void DisplayClassStatus(const char *registrants[], size_t registrantCount, 
    const char *attendees[], size_t attendeeCount)
{
    printf("Not present:\n");
    // Search for those on reg list that do not appear on attendee list.
    for (size_t idx = 0; idx < registrantCount; idx++)
    {
        if (bsearch(&registrants[idx], attendees, attendeeCount, sizeof(attendees[0]), Compare) == NULL)
        {
            printf("    %s\n", registrants[idx]);
        }
    }

    printf("Not registered:\n");
    // Search for those on the attendee list that do not appear on the reg list.
    for (size_t idx = 0; idx < attendeeCount; idx++)
    {
        if (bsearch(&attendees[idx], registrants, registrantCount, sizeof(registrants[0]), Compare) == NULL)
        {
            printf("    %s\n", attendees[idx]);
        }
    }
}
