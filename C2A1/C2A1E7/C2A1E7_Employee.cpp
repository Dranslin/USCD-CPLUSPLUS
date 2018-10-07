/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/01/2018
 * C2A1E7_Employee.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Provides the definition for one overloaded Set function.
 * This method dynamically allocates enough space to hold the
 * input, which will become this instance's name.
 */

#include <cstring>
#include "C2A1E7_Employee.h"

void Employee::Set(const char *value)
{
    name = new char(strlen(value) + 1);
    //memcpy(name, value, (size_t)(strlen(value) + 1));
    strcpy(name,value);
}
