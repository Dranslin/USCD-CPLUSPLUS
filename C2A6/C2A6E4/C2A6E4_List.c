/*
* Nicholas Patience U07985691
* Nickspatience@gmail.com
* C/C++ Programming II : Dynamic Memory and File I/O Concepts
* 134312 Ray Mitchell
* 11/3/2018
* C2A6E4_List.c
* Win 10
* Visual C++ 2017
*
* 
*/

#include "C2A6E4_List-Driver.h"
#include <fstream>

List *CreateList(FILE *fp)
{
    List *head, *walker;
    char readString[MAX_BUFFER_SIZE];

    // Create head node. No data needed for head node
    if ((head = (struct List *)malloc(sizeof(struct List))) == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Begin to read the file
    for (; fscanf(fp, "%s", readString, MAX_BUFFER_SIZE) != -1;)
    {
        walker = head;

        while (walker != NULL)
        {
            if (walker->str == readString)
            {
                walker->count++;
            }
            else if (walker->next != NULL)
            {
                walker = walker->next;
            }
            else
                //else if (walker->next == NULL)
                //else
            {
                //List *newNode = CreateNode();
                List *newNode;
                if ((newNode = (struct List *)malloc(sizeof(struct List))) == NULL)
                {
                    fprintf(stderr, "Memory allocation failed.\n");
                    exit(EXIT_FAILURE);
                }

                newNode->count = 1;

                walker->str = (char *)malloc((sizeof(char) * strlen(readString)));
                strcpy(walker->str, readString);

                walker->next = newNode;
            }
        }





    }

    return head;
}

List *CreateNode()
{
    List *newNode;
    if ((newNode = (struct List *)malloc(sizeof(struct List))) == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    return newNode;
}



List *PrintList(const List *head)
{
    List *walker = head;

    while (walker != NULL)
    {
        printf("%s %d4 ea\n", walker->str, walker->count);
        walker = walker->next;
    }
    return head;
}

void FreeList(List *head)
{
    List *walker = head;

    while (walker->next != NULL)
    {
        free(walker->str);
        free(walker);
    }

    return head;
}