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
* Provides definitions for CreateNode, CreateList, PrintList and FreeList.
* These functions dynamically allocate space for new nodes and each node's
* string, tests provided strings then fills in the node's strings and counts
* for each string, prints out the results, and frees the allocated memory.
*/

#include "C2A6E4_List-Driver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 128

List *CreateNode(const char *targetString);
List *CreateList(FILE *fp);

static int maxStringSize = 0;

// Allocate space for each node and node's string, then return pointer to node
List *CreateNode(const char *targetString)
{
    int currntStringSize = (int)(sizeof(*targetString) / (sizeof(targetString)[0]));
    if (maxStringSize < currntStringSize)
    {
        maxStringSize = currntStringSize;
    }

    List *newNode = (struct List *)malloc(sizeof(struct List));

    // Testing for failure
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize values.
    newNode->next = NULL;
    newNode->count = 1;

    // Allocate space for string, then copy.
    //newNode->str = (char *)malloc(sizeof(char) * (sizeof(targetString) / sizeof(targetString)[0]));
    newNode->str = (char *)malloc((sizeof(char) * (strlen(targetString) + 1)));
    strcpy(newNode->str, targetString);

    return newNode;
}

List *CreateList(FILE *fp)
{
    List *head = NULL, *walker = NULL;
    char readString[MAX_BUFFER_SIZE];

    for (; fscanf(fp, "%s", readString) != EOF;)
    //for (; fscanf(fp, "%s", readString, MAX_BUFFER_SIZE) != -1;)
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
        //printf("Strcmp returns %d\n", strcmp(walker->str, readString));
        while (walker != NULL)
        {
            // If match found, increment count and stop traversing.
            if (strcmp(walker->str, readString) == 0)
            {
                walker->count += 1;
                walker = NULL;
            }
            // Continue walking list.
            else if (walker->next != NULL)
            {
                walker = walker->next;
            }
            // If at end of list and no match, create new node.
            else
            {
                walker->next = CreateNode(readString);
                walker = NULL;
            }
        }
    }
    return head;
}

// Traverses the list and prints out the string and count for each string.
List *PrintList(const List *head)
{
    List *walker = head;

    // Traverse list and print values
    while (walker != NULL)
    {
        printf("%*s %4d ea\n", maxStringSize, walker->str, walker->count);
        walker = walker->next;
    }
    return (const List *)head;
}

// Free two malloc cases, node and node's string
void FreeList(List *head)
{
    List *walker = head, *temp;

    // Traverse through the list
    while (walker->next != NULL)
    {
        temp = walker;
        walker = walker->next;
        // String must be freed first
        free(temp->str);
        free(temp);
    }
}