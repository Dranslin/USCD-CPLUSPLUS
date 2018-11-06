/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/3/2018
 * C2A6E2_SortValues.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Uses the bubble sort method on the specified array to sort in descending order.
 */

#include <cstdlib>
using namespace std;

float *SortValues(float *first, size_t elements)
{
    // End and swapped declared out of loop for persistance.
    // End decrements and swapped has to exist out of do-while loop
    float *end = &first[elements - 1];
    bool swapped;

    do
    {
        swapped = false;
        // Reset flag value
        for (float *walker = first, *trail = first + 1; walker < end; walker++, trail++)
        {
            // Test to see if swap is necessary
            if (*walker < *trail)
            {
                // Save copy of current value and swap next value
                float temp = *walker;
                *walker = *trail;
                *trail = temp;
                swapped = true;
            }
        }
        --end;
    // If no swap occurs, no need to continue.
    } while (swapped);

    return first;
}
