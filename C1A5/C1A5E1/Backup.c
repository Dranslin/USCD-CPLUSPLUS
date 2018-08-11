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

/*

#include <stdio.h>

#define MAX_RESPONDENTS 10
#define MIN_RESPONSE_VALUE (5)
#define MAX_RESPONSE_VALUE (10)
#define ABS(x) ((x < 0) ? (-(x)) : (x))
#define RESPONSE_VALUES ((1 + (MAX_RESPONSE_VALUE) - (MIN_RESPONSE_VALUE)))
#define OUT_OF_RANGE_LIMIT 2

int main(void)
{
    int consecutiveRangeErrors = 0;
    int ratingResponses[RESPONSE_VALUES] = { 0 };
    int currentResponse = 0;

    do
    {
        int userRating;
        printf("Please enter a rating to give:\n");
        scanf("%i", &userRating);

        printf("Debugging... ");
        printf("Check max Val %s\n", (userRating > MAX_RESPONSE_VALUE) ? "true" : "false");
        printf("Check min Val %s\n", (userRating < MIN_RESPONSE_VALUE) ? "true" : "false");

        // check if within boundary of answers
        if ((userRating > MAX_RESPONSE_VALUE) || (userRating < MIN_RESPONSE_VALUE))
        {
            //Error condition
            consecutiveRangeErrors++;
            printf("ERROR: Out of bounds value. Please enter an inbound value.\n");
        }
        else
        {
            // Success condition
            consecutiveRangeErrors = 0;
            currentResponse++;
            printf("\nDebugging... Userrating - min = %d\n", userRating - MIN_RESPONSE_VALUE);
            ratingResponses[userRating - MIN_RESPONSE_VALUE] += 1;
        }

        printf("Debugging... ");
        printf("Check max responses %s\n", (currentResponse < MAX_RESPONDENTS) ? "true" : "false");
        printf("Check out of range %s\n", (consecutiveRangeErrors < OUT_OF_RANGE_LIMIT) ? "true" : "false");

    } while ((currentResponse < MAX_RESPONDENTS) && (consecutiveRangeErrors < OUT_OF_RANGE_LIMIT));

    printf("\nMax val: %i Min val: %i\n", MAX_RESPONSE_VALUE, MIN_RESPONSE_VALUE);
    printf("Rating Responses\n");

    int outputIndex = MAX_RESPONSE_VALUE;
    for (int i = RESPONSE_VALUES - 1; i >= 0; i--)
    {
        printf("%i %i and I is %i\n", outputIndex--, ratingResponses[i], i);
    }

    return 0;
}
*/