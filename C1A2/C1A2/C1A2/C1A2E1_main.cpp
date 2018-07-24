/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 07/22/2018
 * C1A2E1_main.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Simple untested lowercase to uppercase conversion.
 *
 * 1. If a user enters anything other than a lower case character, the use of subtracting an offset value
 *    causes a garbage value to be outputted. The logic only takes into account that the characters lowercase 
 *    characters are a certain value away from their uppercase counterpart. This value is calculated by 'a' - 'A'
 *    Any other shift is meaningless.
 *
 * 2. If a user enters whitespace before their entry, the cin.get will only capture that
 *    whitespace. This function does not discard whitespace characters.
 *
 * DO NOT COPY OR RESTATE MY INSTRUCTIONS IN THE TITLE BLOCK OR ANYWHERE ELSE.
 */

#include <iostream>
const int LOWERTOUPPEROFFSET = 'a' - 'A';

int main()
{
    char characterToConvert;

    std::cout << "Please enter a character to be converted to lowercase:\n";
    std::cin.get(characterToConvert);
    std::cout << "The uppercase equivalent of \'" << characterToConvert << "\' is \'" 
        << char(characterToConvert - LOWERTOUPPEROFFSET) << "\' (decimal value = " 
        << int(characterToConvert - LOWERTOUPPEROFFSET) << ")\n";
    
    return 0;
}
