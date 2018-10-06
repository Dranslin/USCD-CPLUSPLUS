/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/05/2018
 * C2A2E1_CountBitsM.h
 * Win 10
 * Visual C++ 2017
 *
 * Provides macro to get size of number of bits of storage used
 * for the provided object or type.
 */

#ifndef C2A2E1_COUNTBITSM_H
#include <limits.h>
#define C2A2E1_COUNTBITSM_H

#define CountBitsM(X) ((sizeof(X)) * (CHAR_BIT))

#endif // !C2A2E1_COUNTBITSM_H
