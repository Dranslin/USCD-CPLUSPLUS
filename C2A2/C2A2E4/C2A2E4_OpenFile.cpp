/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/06/2018
 * C2A2E4_OpenFile.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Opens the file who's name is specified in filename, or errors out
 * and terminates the program.
 */

#include <fstream>
#include <iostream>

void OpenFile(const char *filename, std::ifstream &infile)
{
    // Open file here
    infile.open(filename, std::fstream::in);
    // Only needs check if file is open. If it is, error and die.
    if (!infile.is_open())
    {
        infile.close();
        std::cerr << "ERROR: File " << filename << " could not be opened.";
        exit(EXIT_FAILURE);
    }
}
