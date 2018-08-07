/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/04/2018
 * C1A4E4_MaxOf.h
 * Win 10
 * Visual C++ 2017
 *
 * Provides macros and inline functions that calculate the
 * larger of two and three values. Three values are calculated
 * by calling the two value and comparing against them.
 */

#ifndef C1A4E4_MAXOF_H
#define C1A4E4_MAXOF_H

#define mMaxOf2(value1, value2) ((value1) > (value2) ? (value1) : (value2))
#define mMaxOf3(value1, value2, value3) (mMaxOf2((value1), mMaxOf2((value2),(value3))))

inline long double fMaxOf2(long double value1, long double value2)
{
    return value1 > value2 ? value1 : value2;
}
inline long double fMaxOf3(long double value1, long double value2, long double value3)
{
    return fMaxOf2(value1, fMaxOf2(value2, value3));
}

#endif // !C1A4E4_MAXOF_H
