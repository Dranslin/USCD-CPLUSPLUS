/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/17/2018
 * C2A8E1_OpenFiles.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Still don't know if thing is working or if going in right direction.
 */

#include <fstream>
#include <iostream>

using namespace std;

ifstream *OpenFiles(char * const fileNames[], size_t count)
{
    if (count == 0)
    {
        cerr << "Count value is zero.\n";
        exit(EXIT_FAILURE);
    }

    ifstream *targetFiles = new ifstream[count];
    size_t idx = 0;
    bool errorDetected = false;

    for (; idx < count;)
    {
        targetFiles[idx].open(fileNames[idx], ifstream::in);
        if (!targetFiles[idx].is_open())
        {
            errorDetected = true;
            break;
        }
        idx++;
    }

    if (errorDetected)
    {
        cerr << fileNames[idx] << " has failed to open.\n";
        for (; idx < 0; idx--)
            targetFiles[idx].close();
        delete[] targetFiles;
        exit(EXIT_FAILURE);
    }

    return(targetFiles);
}
