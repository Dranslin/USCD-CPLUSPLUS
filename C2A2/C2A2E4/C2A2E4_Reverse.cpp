/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/06/2018
 * C2A2E4_Reverse.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Reverses each set of characters in a file, capitalizing each last and 
 * third-to-last character in the process before printing out. Returns
 * any white space or punctuation as normal.
 */

#include <fstream>
#include <iostream>

const int LAST = 1;
const int SECOND_TO_LAST = 3;

// Test cases: whitespace, . ? ! , : ;
inline bool testSeparator(const char *testVal)
{
    return ((isspace(*testVal)) || (*testVal == '.') || (*testVal == '?') || (*testVal == '!') 
        || (*testVal == ',') || (*testVal == ':') || (*testVal == ';')) ? true : false;
}

int Reverse(std::ifstream &infile, const int level)
{
    char thisChar;
    infile.get(thisChar);
    
    // Test for and return EOF
    if (infile.eof()) 
    {
        return EOF;
    }
    // Test for separator characters and return
    else if (testSeparator(&thisChar))
    {
        return (int)thisChar;
    }
    // Find all other characters, capitalize if needed, then print.
    else
    {
        // Recursive call to reverse order of characters.
        int thisSeparator = Reverse(infile, level + 1);
        // If last or third to last, capitalize.
        if ((level == LAST) || (level == SECOND_TO_LAST))
            thisChar = (char)toupper(thisChar);
        std::cout << thisChar;
        return thisSeparator;
    }
}
