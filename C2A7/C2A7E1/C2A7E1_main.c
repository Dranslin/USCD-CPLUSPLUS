/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 11/9/2018
 * C2A7E1_main.c
 * Win 10
 * Visual C++ 2017
 *
 * Modifies the source provided by Professor Ray Mitchell to make
 * the hash table contain binary trees rather than single linked lists.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256                /* size of input buffer */
#define BUFFMT "%255"               /* field width for input buffer scan */
#define MIN_ARGS 3                  /* fewest command line arguments */
#define FILE_ARG_IX 1               /* index of file name argument */
#define BINS_ARG_IX 2               /* index of bin count argument */

typedef struct Node NODE;
struct Node                         /* type of each list node */
{
    char *strng;                    /* string for this node */
    size_t count;                   /* occurrences of this string */
    NODE *left, *right;             /* next node in list */
};

typedef struct                      /* type of table array elements */
{
    size_t nodes;                   /* # of list nodes for this bin */
    NODE *firstNode;                /* 1st node in this bin's list */
} BIN;

typedef struct                      /* type of hash table descriptor */
{
    size_t bins;                    /* bins in hash table */
    BIN *firstBin;                  /* first bin */
} TABLE;

int HashFunction(const char *key, size_t bins);
TABLE *CreateTable(size_t bins);
NODE *BuildTree(BIN *bp, char *str, NODE *pNode);
void PrintBinLeaves(const NODE *pNode);
void PrintTable(const TABLE *hashTable);
void FreeBinLeaves(NODE *pNode);
void FreeTable(TABLE *hashTable);
void *SafeMalloc(size_t size);
FILE *OpenFile(const char *fileName);

//int main(void)
int main(int argc, char *argv[])
{
    char buf[LINE_LEN];              /* word string buffer */
    char fileName[LINE_LEN];         /* file name buffer */
    int howManyBins;                 /* number of bins to create */
    TABLE *hashTable;                /* pointer to hash table */
    FILE *fp;
    //int argc = 3;
    //char *argv[] = { "C2A7E1_main", "TestFile1.txt", "10" };

    /* Read file name from command line */
    if (argc < MIN_ARGS || sscanf(argv[FILE_ARG_IX], BUFFMT "s", fileName) != 1)
    {
        fprintf(stderr, "No file name specified on command line\n");
        return EXIT_FAILURE;
    }
    fp = OpenFile(fileName);

    /* Read bin count from command line */
    if (sscanf(argv[BINS_ARG_IX], "%d", &howManyBins) != 1)
    {
        fprintf(stderr, "No bin count specified on command line\n");
        return EXIT_FAILURE;
    }
    /* allocate table array */
    hashTable = CreateTable((size_t)howManyBins);  

    /*
     * The following loop will read one string at a time from stdin until
     * EOF is reached.  For each string read the BuildList function will
     * be called to update the hash table.
     */
    while (fscanf(fp, BUFFMT "s", buf) != EOF) /* get string from file */
    {
        /* find appropriate bin */
        BIN *bin = &hashTable->firstBin[HashFunction(buf, (size_t)howManyBins)];
        BuildTree(bin, buf, bin->firstNode);        /* put string in list */
    }
    fclose(fp);
    PrintTable(hashTable);                          /* print all strings */
    FreeTable(hashTable);                           /* free the table */
    return(EXIT_SUCCESS);
}

// Provides error checking while allocating memory.
void *SafeMalloc(size_t size)
{
    void *vp;

    if ((vp = malloc(size)) == NULL)
    {
        fputs("Out of memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    return(vp);
}

// Provides file opening and testing for failure of opening.
FILE *OpenFile(const char *fileName)
{
    FILE *fp;

    if ((fp = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "File \"%s\" didn't open.\n", fileName);
        perror(fileName);
        exit(EXIT_FAILURE);
    }
    return fp;
}

int HashFunction(const char *key, size_t bins)  /* get bin value from key */
{
    return((int)(strlen(key) % bins));  /* value is character count % bins */
}

/* CreateTable creates and initializes the hash table and its bins */
TABLE *CreateTable(size_t bins)
{
    TABLE *hashTable;
    BIN *bin, *end;

    hashTable = (TABLE *)SafeMalloc(sizeof(TABLE));   /* alloc desc struct */
    hashTable->bins = bins;                           /* how many bins */
    hashTable->firstBin = (BIN *)
        SafeMalloc(bins * sizeof(BIN));               /* alloc bins */
    end = hashTable->firstBin + bins;                 /* end of bins */

    for (bin = hashTable->firstBin; bin < end; ++bin) /* initialize bins */
    {
        bin->nodes = 0;                               /* no list nodes */
        bin->firstNode = NULL;                        /* no list */
    }
    return(hashTable);
}

/*
 * BuildTree will search the binary tree at pNode for a node representing the
 * string in str.  If found, its string count will be incremented.  If not
 * found, a new node for that string will be created, put in alphabetical
 * order, and its count set to 1.  A pointer to the node for string str is
 * returned.
 */
NODE *BuildTree(BIN *bp, char *str, NODE *pNode)
{
    if (pNode == NULL)                              /* string not found */
    {
        size_t length = strlen(str) + 1;            /* length of string */

        pNode = (NODE *)SafeMalloc(sizeof(NODE));   /* allocate a node */
        pNode->strng = (char *)SafeMalloc(length);
        memcpy(pNode->strng, str, length);          /* copy string */
        pNode->count = 1;                           /* 1st occurrence */
        pNode->left = pNode->right = NULL;          /* no subtrees */
        bp->nodes++;
        if (bp->firstNode == NULL)
            bp->firstNode = pNode;
    }
    else
    {
        int result = strcmp(str, pNode->strng);     /* compare strings */

        if (result == 0)                            /* new string == current */
            ++pNode->count;                         /* increment occurrence */
        else if (result < 0)                        /* new string < current */
            /* traverse left */
            pNode->left = BuildTree(bp, str, pNode->left);     
        else                                       /* new string > current */
            /* traverse right */
            pNode->right = BuildTree(bp, str, pNode->right);    
    }
    return(pNode);
}

// Function for recursive traveling and calling along the binary tree 
// to reach leaves for printing the results.
void PrintBinLeaves(const NODE *pNode)
{
    if (pNode != NULL)                              /* if child exists */
    {
        PrintBinLeaves(pNode->left);                /* traverse left */
        printf("%4d  %s\n", (int)pNode->count, pNode->strng);
        PrintBinLeaves(pNode->right);               /* traverse right */
    }
}

/* PrintTable prints the hash table */
void PrintTable(const TABLE *hashTable)
{
    BIN *bin, *end;

    end = hashTable->firstBin + hashTable->bins;    /* end of bins */
    /* visit bins */
    for (bin = hashTable->firstBin; bin < end; ++bin)  
    {
        NODE *node = bin->firstNode;
        printf("%d entries for bin %d:\n",
            (int)bin->nodes, (int)(bin - hashTable->firstBin));
        // Traverse and print leaves
        PrintBinLeaves(node);
    }
}

// Function for recursive traveling and calling along the binary tree 
// to reach leaves for freeing.
void FreeBinLeaves(NODE *pNode)
{
    if (pNode != NULL)                              /* if child exists */
    {
        FreeBinLeaves(pNode->left);                 /* traverse left */
        FreeBinLeaves(pNode->right);                /* traverse right */
        free(pNode->strng);                         /* free the string */
        free(pNode);                                /* free the node */
    }
}

/* FreeTable frees the hash table */
void FreeTable(TABLE *hashTable)
{
    BIN *bin, *end;

    end = hashTable->firstBin + hashTable->bins;    /* end of bins */
    /* visit bins */
    for (bin = hashTable->firstBin; bin < end; ++bin)  
    {
        NODE *rootNode = bin->firstNode;
        FreeBinLeaves(rootNode);
    }
    free(hashTable->firstBin);                      /* free all bins */
    free(hashTable);                                /* free table descriptor */
}
