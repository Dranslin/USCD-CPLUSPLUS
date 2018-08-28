/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/27/2018
 * C1A7E2_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Prompts user to fill in information for the food struct that contains
 * c-string name and two ints for weight and calorie count respectively.
 * The name is put into the buffer and then just enough memory is allocated
 * to be put back into the structure before printing all the results out.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define LUNCH_ITEMS 10
#define BUFFERLENGTH 128
#define STARTINDEX 2

int main(void)
{
    int lsName = 0, lsWeight = 0, lsCalories = 0;   // Capture largest least sig value for alignment

    struct Food
    {
        char *name; /* "name" attribute of food */
        int weight, calories; /* "weight" and "calories" attributes of food */
    } lunch[LUNCH_ITEMS] = {{"apple", 4, 100}, {"salad", 2, 80}};

    // Fill in rest of the lunch array
    for (int index = 0; index < LUNCH_ITEMS; index++)
    {
        size_t cStringLength = 0;
        if (index >= STARTINDEX)
        {
            char buffer[BUFFERLENGTH]; // Captures c-string input
            
            printf("Please enter data to fill the lunch structure.\nFor each entry"
                " please enter a name, weight value, and calorie value on "
                "a single line separated by spaces.\n");
            scanf("%127s %i %i", buffer, &lunch[index].weight, &lunch[index].calories);

            cStringLength = strlen(buffer) + 1;
            char *namePtr; // for allocating just enough space for the c-string
            if ((namePtr = (char *)malloc(cStringLength * sizeof(char))) == NULL)
            {
                // Allocation failed.
                fprintf(stderr, "Memory Allocation failed");
                exit(EXIT_FAILURE);
            }
            else
            {
                // copy value at buffer into nameptr, then assign to lunch at index
                memcpy(namePtr, buffer, cStringLength * sizeof(char));
                lunch[index].name = namePtr;
            }
        }

        // get necessary alignment space based off longest length value for each variable in struct
        int lsCurrentName = (int)cStringLength;
        //int lsCurrentName = (int)strlen(lunch[index].name);     // # of characters for name
        int lsCurrentCal = (int)floor(log10(lunch[index].calories)) + 1;    // # of digits for cal
        int lsCurrentWeight = (int)floor(log10(lunch[index].weight)) + 1;  // # of digits for weight
        // # chars for name and # of digits for weight
        if (lsName < lsCurrentName) 
            lsName = lsCurrentName;
        if (lsWeight < lsCurrentWeight) 
            lsWeight = lsCurrentWeight;
        if (lsCalories < lsCurrentCal) 
            lsCalories = lsCurrentCal;
    }

    printf("Name Weight Calories\n---- ----- ---------\n");
    for (int index = 0; index < LUNCH_ITEMS; index++)
    {
        printf("%-*s %*d %*d\n", lsName, lunch[index].name, 
            lsWeight, lunch[index].weight, lsCalories, lunch[index].calories);
        if (index >= STARTINDEX)
            free(lunch[index].name);
    }

    return 0;
}
