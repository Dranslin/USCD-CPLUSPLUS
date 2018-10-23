/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/20/2018
 * C2A4E1_ComputeAverages.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Traverses the targetArray by means of 4D and compact pointer method
 * to calculate the average of all elements.
 */

#include "C2A4E1_ArraySize.h"

void ComputeAverages(float (*targetArray)[DIM1][DIM2][DIM3], float *nestedAvg, float *linearAvg)
{
    float avg = 0;

    // Traverse array by 4D indexing to get sum for average.
    for (int index0 = 0; index0 < DIM0; index0++)
        for (int index1 = 0; index1 < DIM1; index1++)
            for (int index2 = 0; index2 < DIM2; index2++)
                for (int index3 = 0; index3 < DIM3; index3++)
                    avg += targetArray[index0][index1][index2][index3];

    *nestedAvg = avg / TOTALCOUNT;
    avg = 0;
    
    // Traverse array by compact pointer to get sum for average.
    for (float *traveler = (float *)targetArray; 
        traveler < &targetArray[DIM0 - 1][DIM1 - 1][DIM2 - 1][DIM3]; traveler++)
        avg += *traveler;

    *linearAvg = avg / TOTALCOUNT;
}
