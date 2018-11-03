#include "stdio.h"

typedef int(*pPrintf)(const char*, ...);
typedef int(*pPuts)(const char*);

pPrintf getPrintf(void)
{
    return &printf;
}
//or if this is what you've tried to do:
int* getPrintfAsIntPointer(void)
{
    return (int*)&printf;
}

pPuts getPuts()
{
    return &puts;
}

int main()
{
    getPrintf()("%s\n", "hello world");
    getPuts()("hello world\n");
    return 0;
}