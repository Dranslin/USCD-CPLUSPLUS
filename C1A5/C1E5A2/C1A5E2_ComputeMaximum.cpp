/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/11/2018
 * C1A5E2_ComputeMaximum.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Computes minimum value of two.
 */

double &ComputeMaximum(const double &valueOne, const double &valueTwo)
{
    return (double &)(valueOne >= valueTwo ? valueOne : valueTwo);
}
