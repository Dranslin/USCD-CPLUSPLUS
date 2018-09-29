/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 09/29/2018
 * C2A1E1_Macros.h
 * Win 10
 * Visual C++ 2017
 *
 * Provides three different function-like macros: Product, Negate, and Elements
 * Product provides the multipulcation of the the arguments.
 * Negate provides the negation or opposite of the argument.
 * Elements provides a count of the number of array elements in the array argument.
 */

#ifndef C2A1E1_MACROS_H
#define Product(X,Y) ((X)*(Y))
#define Negate(X) (-(X))
#define Elements(X) (sizeof(X)/sizeof(0[X]))
#endif // !C2A1E1_MACROS_H
