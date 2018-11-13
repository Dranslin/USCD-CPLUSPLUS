/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/9/2018
 * C2A7E2_ListHex.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Reads contents of infile byte-by-byte and outputs the read
 * data as pairs of hex decimals.
 */

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void ListHex(ifstream &inFile, int bytesPerLine)
{
    int lineCounter = 0;                // # of entries for new line counter
    char currentByte = 0;               // buffer variable
    cout << setfill('0') << hex;        // Set fillers and digit mode

    // Read until end of file is reached.
    inFile.read(&currentByte, 1);
    do
    {
        // Read single byte of data and pass to temp for u char conversion
        unsigned char temp = (unsigned char)currentByte;

        cout << " " << setw(2) << static_cast<unsigned int>(temp);

        // Check for number of bytes on the line, adding new line if needed
        lineCounter++;
        if (lineCounter == bytesPerLine)
        {
            cout << "\n";
            lineCounter = 0;
        }
    } while (inFile.read(&currentByte, 1));
}
