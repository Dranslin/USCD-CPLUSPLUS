#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "TestFile1.txt"
#define MAX_BUFFER_SIZE 128

typedef struct List
{
    struct List *next;   // pointer to the next List List
    char *str;           // pointer to the string represented
    int count;           // # of occurrences of this string
} List;


FILE *OpenFile(const char *fileName);
List *CreateList(FILE *fp);
List *PrintList(const List *head);
void FreeList(List *head);
List *CreateNode();

int main(void)
{
    FILE *fp = OpenFile(FILENAME);
    List *head = CreateList(fp);

    fclose(fp);
    FreeList(PrintList(head));

    return EXIT_SUCCESS;
}

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

    while (walker!= NULL)
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