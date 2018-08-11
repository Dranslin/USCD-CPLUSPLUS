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
#define MIN_RESPONSE_VALUE (5)
#define MAX_RESPONSE_VALUE (10)
#define ABS(x) ((x < 0) ? (-(x)) : (x))
#define RESPONSE_VALUES ((1 + (MAX_RESPONSE_VALUE) - (MIN_RESPONSE_VALUE)))
#define OUT_OF_RANGE_LIMIT 5

int main(void)
{
    int consecutiveRangeErrors = 0;
    int ratingResponses[RESPONSE_VALUES] = {0};
    int currentResponse = 0;

    do
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

     // Until exceeding number of responses or repeated errors
    } while ((currentResponse < MAX_RESPONDENTS) && (consecutiveRangeErrors < OUT_OF_RANGE_LIMIT));

    printf("Rating Responses\n");

    int outputIndex = MAX_RESPONSE_VALUE;

    // Print results starting with highest value and going down
    for (int i = RESPONSE_VALUES - 1; i >= 0; i--)
    {
        printf("%i %i\n", outputIndex--, ratingResponses[i]);
    }

    return 0;
}