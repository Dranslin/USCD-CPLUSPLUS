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
#include <stdio.h>

#define MAX_BUFFER_SIZE 128

List *CreateList(FILE *fp)
{
    List *head = NULL, *walker = NULL;
    char readString[MAX_BUFFER_SIZE];

    for (; fscanf(fp, "%s", readString, MAX_BUFFER_SIZE) != -1;)
    {
        // Test if head node is created yet.
        if (head == NULL)
        {
            printf("List is empty.\n");
            head = CreateNode(readString);
        }

        // Setup for traversing list
        walker = head;

        // Traverse list: check for string, then check for next node, 
        // then create if not there.
        printf("Strcmp returns %d\n", strcmp(walker->str, readString));
        while (walker != NULL)
        {
            if (strcmp(walker->str, readString) == 0)
            {
                walker->count += 1;
                walker = walker->next;
            }
            else if (walker->next != NULL)
            {
                walker = walker->next;
            }
            else
            {
                walker->next = CreateNode(readString);
                walker = NULL;
            }
        }
    }
    return head;
}

List *CreateNode(const char *targetString)
{
    List *newNode = (struct List *)malloc(sizeof(struct List));

    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->next = NULL;
    newNode->count = 0;

    newNode->str = (char *)malloc((sizeof(char) * strlen(targetString)));
    strcpy(newNode->str, targetString);

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
    List *walker = head, *temp;

    while (walker->next != NULL)
    {
        temp = walker;
        walker = walker->next;

        free(temp->str);
        free(temp);
    }
    return head;
}