/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/05/2018
 * C2A2E1_CountIntBitsF.c
 * Win 10
 * Visual C++ 2017
 *
 * Counts number of bits used in the int datatype.
 */

int CountIntBitsF(void)
{
    int shiftCount = 0;
    
    for (unsigned int value = 1; value > 0; value <<= 1)
        shiftCount++;
    /*while (value > 0)
    {
        shiftCount++;
        value = value << 1;
    }*/
    return shiftCount;
}
