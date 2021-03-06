#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Begin instructor header

#define FILENAME "TestFile1.txt"
#define MAX_BUFFER_SIZE 128

typedef struct List
{
    struct List *next;   // pointer to the next List List
    char *str;           // pointer to the string represented
    int count;           // # of occurrences of this string
} List;

// End instructor header





// Begin instructor mainline
FILE *OpenFile(const char *fileName);
List *CreateList(FILE *fp);
List *PrintList(const List *head);
void FreeList(List *head);
List *CreateNode(const char *cString);

int main(void)
{
    FILE *fp = OpenFile(FILENAME);
    List *head = CreateList(fp);

    fclose(fp);
    FreeList(PrintList(head));

    return EXIT_SUCCESS;
}

// End instructor mainline






// Begin my OpenFile

FILE *OpenFile(const char *fileName)
{
    FILE *source = NULL;

    // If file fails to open, terminate program
    if ((source = fopen(fileName, "r")) == NULL)
    {
        // Fail condition: Alert and exit program.
        fprintf(stderr, "File %s failed to open.", fileName);
        exit(EXIT_FAILURE);
    }
    return source;
}

// End my OpenFile



// Begin my List

// Creates the linked list, testing for matching strings in linked list
// increments counts for each matched string to a node, and creates nodes
// if not found.
List *CreateList(FILE *fp)
{
    List *head = NULL, *walker = NULL;
    char readString[MAX_BUFFER_SIZE];

    for (; fscanf(fp, "%s", readString, MAX_BUFFER_SIZE) != -1;)
    {
        // Test if head node is created yet.
        if (head == NULL)
        {
            printf("List is empty. Creating first node...\n");
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


// Allocate space for each node and node's string, then return pointer to node
List *CreateNode(const char *targetString)
{
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


// Traverses the list and prints out the string and count for each string.
List *PrintList(const List *head)
{
    List *walker = head;

    // Traverse list and print values
    while (walker!= NULL)
    {
        printf("%-13s %3d ea\n", walker->str, walker->count);
        walker = walker->next;
    }
    return head;
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
    return head;
}

// End my List




/*

List *head, *walker;
char readString[MAX_BUFFER_SIZE];

// Create head node. No data needed for head node
head = CreateNode();
if ((head = (struct List *)malloc(sizeof(struct List))) == NULL)
{
fprintf(stderr, "Memory allocation failed.\n");
exit(EXIT_FAILURE);
}
head->next = NULL;

// Begin to read the file
for (;fscanf(fp, "%s", readString, MAX_BUFFER_SIZE) != -1;)
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
List *newNode = CreateNode();
//List *newNode;
//newNode = (struct List *)malloc(sizeof(struct List));
if (newNode == NULL)
//if ((newNode = (struct List *)malloc(sizeof(struct List))) == NULL)
{
fprintf(stderr, "Memory allocation failed.\n");
exit(EXIT_FAILURE);
}

newNode->count = 1;
newNode->next = NULL;

walker->str = (char *)malloc((sizeof(char) * strlen(readString)));
strcpy(walker->str, readString);

walker->next = newNode;
walker = NULL;
}
}
}

*/