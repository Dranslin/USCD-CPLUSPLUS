/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/3/2018
 * C2A6E2_GetValues.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Prompts user to enter values into the array to be sorted
 */

#include <iostream>
#include <cstdlib>

using namespace std;

float *GetValues(float *first, size_t elements)
{
    // Walk through full array and fill user entered values
    for (float *walker = first, *last = &first[elements]; walker < last; walker++)
    {
        cout << "Please enter a value to fill into the set:\n";
        cin >> *walker;
    }
    return first;
}
