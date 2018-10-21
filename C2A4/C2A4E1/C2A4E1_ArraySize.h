/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/20/2018
 * C2A4E1_ArraySize.h
 * Win 10
 * Visual C++ 2017
 *
 * Provides values for each of the array definitions
 */

#ifndef C2A4E1_ARRAYSIZE_H
#define C2A4E1_ARRAYSIZE_H

const int DIM0 = 10;
const int DIM1 = 7;
const int DIM2 = 6;
const int DIM3 = 8;
const int TOTALCOUNT = DIM0 + (DIM0 * DIM1) +
    (DIM0 * DIM1 * DIM2) + (DIM0 * DIM1 * DIM2 * DIM3);

#endif // !C2A4E1_ARRAYSIZE_H
