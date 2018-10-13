/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/12/2018
 * C2A3E2_TestDeclarations.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Creates declaractions for the following cases
 * 1. Declares cHelp to be a function returning a reference to a char that has
 * a parameter named help thats a reference to a float.
 * 2. Declares abc to be a pointer to an array of 9 pointers to shorts.
 * 3. Declares def to be a reference to a pointer to an array of 9 pointers to shorts.
 * 4. Declares dpA to be an array of 9 pointers to doubles.
 * 5. Type casts(C - style) dpA to a pointer to an array of 9 pointers to shorts
 * and assigns the result to abc.
 */

const int ARRAYVALUE = 9;

void TestDeclarations()
{
    char &cHelp(float &help);               //1
    short *(*abc)[ARRAYVALUE];              //2
    short *(*&def)[ARRAYVALUE] = abc;       //3
    double *dpA[ARRAYVALUE];                //4
    abc = (short *(*)[ARRAYVALUE])dpA;      //5
}
