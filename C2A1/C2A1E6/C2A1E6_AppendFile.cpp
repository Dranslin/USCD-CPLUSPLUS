/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/01/2018
 * C2A1E6_AppendFile.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Reads two different files, one text file, and one binary file.
 * Appends the information from each file to the end of a created
 * output file. Cycles through each file twice.
 */

#include <iostream>
#include <fstream>

using namespace std;

int AppendFile(const char *inFile, const char *outFile)
{
    ifstream sourceFile(inFile, ios_base::binary);
    if (sourceFile.is_open())
    {
        ofstream destFile(outFile, ios_base::app | ios_base::binary);
        if (destFile.is_open())
        {
            char charEntry;
            // Read sourceFile until EoF then write in destFile.
            while (sourceFile.get(charEntry))
            {
                destFile.put(charEntry);
            }
            //char charEntry;
            //// Read through character at a time... seeking better way.
            //while (!sourceFile.eof())
            //{
            //    sourceFile.get(charEntry);
            //    destFile.put(charEntry);
            //}
            destFile.close();
        }
        // Destination file open failure
        else            
        {
            sourceFile.close();
            cerr << "ERROR: File " << outFile << " could not be opened.";
            exit(EXIT_FAILURE);
        }
        sourceFile.close();
    }
    // Source file open failure
    else                
    {
        cerr << "ERROR: File " << inFile << " could not be opened.";
        exit(EXIT_FAILURE);
    }
    return 0;
}
