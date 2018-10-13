/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/12/2018
 * C2A3E3_RecordOpinions.c
 * Win 10
 * Visual C++ 2017
 *
 * Prompts user to keep entering raitings that are between the positive and 
 * negative ENDPOINT value to be stored and counted. When the TERMINATE 
 * value is entered, the prompting will end and the results of the count 
 * will be displayed in a table. 
 * 
 * The indexing of each response into the array is based on the value 
 * provided, being entered at that index. 
 * Ex: for a value entered of -4, the rating will be stored a valueArray[-4].
 */

#include <stdio.h>

#define ENDPOINT 6
#define TERMINATE 99
#define ARRAYLENGTH ((ENDPOINT * 2) + 1)

void RecordOpinions(void)
{
    int valueArray[ARRAYLENGTH] = {0};
    int userresponse = 0;
    // For using negative and positive indexes.
    int *ixp = &valueArray[ENDPOINT];
    
    while (userresponse != TERMINATE)
    {
        printf(
            "Please enter a rating for a product that ranges from -%d to %d\n" 
            "or enter %d to terminate.\n", ENDPOINT, ENDPOINT, TERMINATE);
        scanf("%d", &userresponse);
        // Places result in the numbered index. Ex -2 is at valueArray[-2]
        if ((userresponse >= -ENDPOINT) && (userresponse <= ENDPOINT))
            ixp[userresponse]++;
    }

    // Prints table of results
    printf(
        "Terminate value is: %d\n"
        "Rating   Responses\n"
        "------   ---------\n", TERMINATE);
    for (int index = -ENDPOINT; index <= ENDPOINT; index++)
    {
        printf("%3d        %3d\n", index, valueArray[index + ENDPOINT]);
    }
    return;
}
