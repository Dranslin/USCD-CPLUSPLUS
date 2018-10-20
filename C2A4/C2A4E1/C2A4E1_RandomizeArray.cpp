/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/20/2018
 * C2A4E1_RandomizeArray.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Seeds the rand function using RTC, then traverses targetArray
 * filling each element with a random number generated from rand.
 */

#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "C2A4E1_ArraySize.h"

void RandomizeArray(float(*targetArray)[DIM1][DIM2][DIM3])
{
    // Seed rand function.
    srand(time(NULL));

    // Traverse array and fill with random numbers.
    for(float *tempTarget = (float *)targetArray; tempTarget < &targetArray[DIM0-1][DIM1 - 1][DIM2 - 1][DIM3]; tempTarget++)
    //for (tempTarget = (float *)targetArray; tempTarget < (float *)(&targetArray + 1); tempTarget++)
        *tempTarget = rand();
}
