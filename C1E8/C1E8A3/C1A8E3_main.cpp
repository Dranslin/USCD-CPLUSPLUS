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

using std::cin;
using std::cout;
using std::cerr;

int main(int argc, char *argv[])
//int main()
{
    //char *argv[] = { "sourceFile", "destFile". "This", "That" };
    //int argc = sizeof(argv) / sizeof(argv[0]);

    if (argc == 5)
    {

    }
    else
    {
        cerr <<"ERROR: Incorrect number of arguements detected.";
        exit(EXIT_FAILURE);
    }

    return 0;
}
