/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/06/2018
 * C2A2E2_Rotate.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Rotates the bits in the object so that any values that fall off in the bit
 * shift get placed to the left or right of the result.
 */

int CountIntBitsF();

unsigned Rotate(unsigned object, int count)
{
    int bitSize = CountIntBitsF();
    int numberOfRotations = count % bitSize;
    // If negative, left shift.
    if (count < 0) 
    {
        numberOfRotations = -numberOfRotations;
        unsigned leftShift = object << numberOfRotations;
        unsigned rightshift = object >> bitSize - numberOfRotations;
        object = leftShift | rightshift;
    }
    // If positive, right shift.
    else
    {
        unsigned rightshift = object >> numberOfRotations;
        unsigned leftShift = object << bitSize - numberOfRotations;
        object = leftShift | rightshift;
    }
    return object;
}
