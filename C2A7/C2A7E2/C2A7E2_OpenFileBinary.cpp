/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/9/2018
 * C2A7E2_OpenFileBinary.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Opens the file specified in filename in binary mode.
 */

#include <fstream>
#include <iostream>

using namespace std;

void OpenFileBinary(const char *fileName, ifstream &inFile)
{
    inFile.open(fileName, ios_base::binary);
    // Test for failure of opening.
    if (!inFile.is_open())
    {
        cerr << "Unable to find file " << fileName << "\n";
        exit(EXIT_FAILURE);
    }
}
