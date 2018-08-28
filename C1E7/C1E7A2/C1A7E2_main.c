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

#define LUNCH_ITEMS 10
#define BUFFERLENGTH 128

int main(void)
{
    char buffer[BUFFERLENGTH];
    struct Food
    {
        char *name; /* "name" attribute of food */
        int weight, calories; /* "weight" and "calories" attributes of food */
    } lunch[LUNCH_ITEMS] = { {"apple", 4, 100}, {"salad", 2, 80} };

    for (int index = 2; index < LUNCH_ITEMS; index++)
    {
        printf("Please enter data to fill the lunch structure. For each entry"
            " please enter a name, weight value, and calorie value on "
            "a single line separated by spaces.\n");
        scanf("%s %i %i", buffer, &lunch[index].weight, &lunch[index].calories);

        printf("Sizeof: %d and filled with %s \n", strlen(buffer), buffer);
        printf("Name: %s Weight: %d Calories: %d\n", buffer, lunch[index].weight, lunch[index].calories);

        char *namePtr;
        if ((namePtr = (char *)malloc((strlen(buffer) + 1) * sizeof(char))) == NULL)
        {
            printf("stderr\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            lunch[index].name = namePtr = buffer;
        }
        printf("Nameptr: %s\n", namePtr);
    }
    printf("Name Weight Calories\n---- ----- ---------\n");
    for (int index = 0; index < LUNCH_ITEMS; index++)
    {
        printf("%s %d %d\n", lunch[index].name, lunch[index].weight, lunch[index].calories);
    }

    return 0;
}
