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

float *SortValues(float *first, size_t elements)
{
    int swapped;
    do
    {
        // Reset flag value
        swapped = 0;
        for (float *walker = first, *end = &first[elements - 1]; walker < end; walker++)
        {
            // Test to see if swap is necessary
            if (*walker < *(walker + 1))
            {
                // Save copy of current value and swap next value
                float temp = *walker;
                *walker = *(walker + 1);
                *(walker + 1) = temp;
                swapped = 1;
            }
        }
    // If no swap occurs, no need to continue.
    } while (swapped);

    return first;
}
