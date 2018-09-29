/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 09/02/2018
 * C1A8E3_main.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Takes in command line arguments for a source file, destination file
 * target sequence of characters and replacement sequence of characters.
 * Performs a replacement of the targeted sequence in every line of the
 * source and saves the results to the destination file
 *
 * argv[1] name of file to search through
 * argv[2] name of file to output to
 * argv[3] sequence of characters to find
 * argv[4] sequence of characters to replace with
 */

#include <iostream>
#include <fstream>
#include <cstring>

const int BUFFERSIZE = 256;
const int TARGETARGCOUNT = 5;
const int FILESOURCELOC = 1;
const int DESTFILELOC = 2;
const int TARGETSTRINGLOC = 3;
const int REPLACESTRINGLOC = 4;

using namespace std;

//int main()
int main(int argc, char *argv[])
{
    //char *argv[] = { "maincpp", "sourceFile.txt", "destFile.txt", "\"string literal\"", "TESTING"};
    //int argc = sizeof(argv) / sizeof(argv[0]);
    if (argc == TARGETARGCOUNT)  // Check for proper number of arguments
    {
        ifstream sourceFile(argv[FILESOURCELOC]);
        if (sourceFile.is_open())   // Test source file open
        {
            ofstream destFile(argv[DESTFILELOC]);
            if (destFile.is_open())     // Test destination file open
            {
                char buffer[BUFFERSIZE];
                int repSize = strlen(argv[TARGETSTRINGLOC]); // Hint violation
                // Run through each line of input
                while (sourceFile.getline(buffer, sizeof(buffer)))
                {
                    char *cp1;
                    //Capture up to next instance of target word
                    for (cp1 = buffer; char *cp2 = strstr(cp1, argv[TARGETSTRINGLOC]);)
                    {
                        // Writes up to after first instance of replacement enounter
                        // then adds replacement word before setting location to next index
                        // after replacement.
                        destFile.write(cp1, cp2 - cp1);
                        destFile << argv[REPLACESTRINGLOC];
                        //cp1 = cp2 + sizeof(cp1) / sizeof(cp1[0]);
                        cp1 = cp2 + repSize;
                    }
                    if (sourceFile.eof())
                    {
                        break;
                    }
                    destFile << cp1 << "\n";
                }
                destFile.close();
                sourceFile.close();
            }
            // Destination file open failure
            else 
            {
                cerr << "ERROR: File " << argv[DESTFILELOC] << " could not be opened.";
                exit(EXIT_FAILURE);
            }
        }
        // Source file open failure
        else
        {
            cerr << "ERROR: File " << argv[FILESOURCELOC] << " could not be opened.";
            exit(EXIT_FAILURE);
        }
        ofstream destinationFile("testOut.txt");
    }
    // Incorrect number of args failure
    else
    {
        cerr << "ERROR: Incorrect number of arguments detected.";
        exit(EXIT_FAILURE);
    }
    return 0;
}
