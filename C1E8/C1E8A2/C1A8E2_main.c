/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 09/02/2018
 * C1A8E2_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Takes in command line arguments. Runs a test to verify that there are
 * enough arguments to designate a file name and a number count to specify
 * how many lines to be displayed per group. Program then reads the text from
 * the file until the end of file, or until the number of lines have been printed
 * File will close and program will end if EOF is found, or if after the group
 * has been printed that anything other than the enter key has been entered.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFERLIMIT 256
#define TARGETARGCOUNT 3
#define LINEGROUPINDEX 2
#define FILENAMEINDEX 1

//int main(void)
int main(int argc, char *argv[])
{
    //char *argv[] = {"testprog", "TestFile1.txt", "3"};
    //int argc = sizeof(argv) / (sizeof(argv[0]));
    //Test argument count
    if (argc == TARGETARGCOUNT)
    {
        int timesToRun = atoi(argv[LINEGROUPINDEX]);

        // Test integer conversion
        if (timesToRun && (atoi(argv[LINEGROUPINDEX]) > 0))
        {
            FILE *readFile;
            // Test file open
            if ((readFile = fopen(argv[FILENAMEINDEX], "r")) != NULL)
            {
                do
                {
                    for (int readIndex = 0; readIndex < timesToRun; readIndex++)
                    {
                        char *buffer[BUFFERLIMIT];
                        //if (fgets(&buffer, sizeof(buffer), readFile) != NULL)
                        //{
                        //    printf("%s", &buffer);
                        //}
                        //else
                        //{
                        //    exit(EXIT_SUCCESS);
                        //}
                        fgets(&(buffer[0]), BUFFERLIMIT, readFile);
                        if (feof(readFile) != 0)
                        {
                            exit(EXIT_SUCCESS);
                        }
                        printf("%s", buffer);
                    }
                } while (getc(stdin) == '\n');

                fclose(readFile);
            }
            // Failed to open file
            else 
            {
                fprintf(stderr, "ERROR: Unable to open file %s.\n", argv[FILENAMEINDEX]);
                exit(EXIT_FAILURE);
            }
        }
        // Non-valid integer value for number of lines to run
        else 
        {
            fprintf(stderr, "ERROR: Second argument not a valid number.");
            exit(EXIT_FAILURE);
        }
    }
    // Not correct number of arguments provided
    else 
    {
        fprintf(stderr, "ERROR: Incorrect number of arguments detected.");
        exit(EXIT_FAILURE);
    }

    return 0;
}
