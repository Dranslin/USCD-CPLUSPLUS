// Testbed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
    int x = 7;
    std::cout << ++x;
    printf("%i", x--);
    std::cout << " ";
    printf("%f", x);

    system("pause");
    return(EXIT_SUCCESS);
}

