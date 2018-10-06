/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/06/2018
 * C2A2E2_CountIntBitsF.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Counts number of bits used in the int datatype.
 */

int CountIntBitsF()
{
    int shiftCount = 0;
    // Continue shifting until value of 1 has falled off
    for (unsigned int value = 1; value > 0; value <<= 1)
        shiftCount++;
    return shiftCount;
}
