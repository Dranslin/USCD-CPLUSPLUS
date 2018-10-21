/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/20/2018
 * C2A4E1_WorkerFunction.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Initializes test array and calls RandomizeArray 
 * and ComputeAverages functions
 */

#include "C2A4E1_ArraySize.h"

void RandomizeArray(float (*targetArray)[DIM1][DIM2][DIM3]);
void ComputeAverages(float (*targetArray)[DIM1][DIM2][DIM3], float *nestedAvg, float *linearAvg);

void WorkerFunction(float *nestedAvg, float *linearAvg)
{
    float testArray[DIM0][DIM1][DIM2][DIM3];

    // Fill array with random numbers
    RandomizeArray(testArray);
    // Calculate average of all elements
    ComputeAverages(testArray, nestedAvg, linearAvg);
}
