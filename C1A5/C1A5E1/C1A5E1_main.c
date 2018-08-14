/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/11/2018
 * C1A5E1_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Computes minimum value of two.
 */

#include <stdio.h>

#define MAX_RESPONDENTS 20
#define MIN_RESPONSE_VALUE 5
#define MAX_RESPONSE_VALUE 10
#define RESPONSE_VALUES (1 + MAX_RESPONSE_VALUE - MIN_RESPONSE_VALUE)
#define OUT_OF_RANGE_LIMIT 5

int main(void)
{
    int consecutiveRangeErrors = 0;
    int ratingResponses[RESPONSE_VALUES] = {0};

    // Until Max Respondents or Out of Range limit reached
    // Keep taking in new ratings.
    for (int currentResponse = 0; (currentResponse < MAX_RESPONDENTS) &&
        (consecutiveRangeErrors < OUT_OF_RANGE_LIMIT); currentResponse++)
    {
        int userRating;
        printf("Please enter a rating to give:\n");
        scanf("%i", &userRating);

        // check if within boundary of answers
        if ((userRating > MAX_RESPONSE_VALUE) || (userRating < MIN_RESPONSE_VALUE))
        {
            // Error condition - add to error counter
            consecutiveRangeErrors++;
            printf("ERROR: Out of bounds value. Please enter an inbound value.\n");
        }
        else
        {
            // Success condition - reset error, increment count and increment array
            consecutiveRangeErrors = 0;
            currentResponse++;
            ratingResponses[userRating - MIN_RESPONSE_VALUE] += 1;
        }
    }
    
    printf("Rating Responses\n------ ---------\n");

    int outputIndex = MAX_RESPONSE_VALUE;

    // Print results starting with highest value and going down
    for (int indexCounter = RESPONSE_VALUES - 1; indexCounter >= 0; indexCounter--)
    {
        printf("%5i %6i\n", outputIndex--, ratingResponses[indexCounter]);
    }
     
    return 0;
}
