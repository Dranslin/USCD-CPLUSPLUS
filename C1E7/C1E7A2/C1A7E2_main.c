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
#include <string.h>

#define LUNCH_ITEMS 10
#define BUFFERLENGTH 128
#define STARTINDEX 2
#define NAMESPACER 15
#define WEIGHTSPACER 4
#define CALORIESPACER 4

int main(void)
{
    struct Food
    {
        char *name; /* "name" attribute of food */
        int weight, calories; /* "weight" and "calories" attributes of food */
    } lunch[LUNCH_ITEMS] = {{"apple", 4, 100}, {"salad", 2, 80}};

    // Fill in rest of the lunch array
    for (int index = 0; index < LUNCH_ITEMS; index++)
    {
        //size_t cStringLength = 0;
        if (index >= STARTINDEX)
        {
            char buffer[BUFFERLENGTH]; // Captures c-string input
            
            printf("Please enter data to fill the lunch structure.\nFor each entry"
                " please enter a name, weight value, and calorie value on "
                "a single line separated by spaces.\n");
            scanf("%127s %i %i", buffer, &lunch[index].weight, &lunch[index].calories);

            size_t cStringLength = strlen(buffer) + 1;
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
    }
    printf("Name Weight Calories\n---- ----- ---------\n");
    for (int index = 0; index < LUNCH_ITEMS; index++)
    {
        printf("%-*s %*d %*d\n", NAMESPACER, lunch[index].name,
            WEIGHTSPACER, lunch[index].weight, CALORIESPACER, lunch[index].calories);
        if (index >= STARTINDEX)
            free(lunch[index].name);
    }

    return 0;
}
