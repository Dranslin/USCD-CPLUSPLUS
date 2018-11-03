/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/27/2018
 * C2A5E4_OpenFile.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Opens the designmated file or errors out an ddies.
 */

#include <fstream>
#include <iostream>
using namespace std;

void OpenFile(const char *fileName, ifstream &inFile)
{
    inFile.open(fileName);
    // Test for failure of opening.
    if (!inFile.is_open())
    {
        cerr << "Unable to find file " << fileName << "\n";
        exit(EXIT_FAILURE);
    }
}
