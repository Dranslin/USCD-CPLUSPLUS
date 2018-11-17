/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/17/2018
 * C2A8E1_MergeAndDisplay.cpp
 * Win 10
 * Visual C++ 2017
 *
 * This thing definately needs more work, but maybe going in right direction?
 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 512;

void MergeAndDisplay(ifstream files[], size_t count)
{
    char buffer[MAX_SIZE];
    bool allClosed = false;

    while (!allClosed)
    {
        for (size_t idx = 0; idx < count; idx++)
        {
            if (files[idx].is_open())
            {
                if (!(files[idx].getline(buffer, sizeof(buffer))))
                {
                    files[idx].close();
                }
                else
                {
                    cout << buffer << "\n";
                }
            }
        }

        bool closedFlag = true;
        for (size_t idx = 0; idx < count; idx++)
        {
            if (files[idx].is_open())
            {
                closedFlag = false;
                break;
            }
        }
        if (closedFlag)
            allClosed = true;
    }
}
