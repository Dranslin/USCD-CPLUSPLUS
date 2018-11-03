/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/27/2018
 * C2A5E4_DetectFloats.cpp
 * Win 10
 * Visual C++ 2017
 *
 *
 */

#include "C2A5E4_StatusCode-Driver.h"
#include <iostream>

using namespace std;

StatusCode DetectFloats(const char *chPtr)
{
    enum States
    {
        START,
        PREFIX_START,
        PREFIX,
        NO_WHOLE,
        WHOLE,
        FRACT,
        EXPONENT,
        SIGNED,
        DIGIT,
        END_FAILURE,
        END_SUCCESS
    } state = START;

    //for (int inChar = toupper(*chPtr); inChar != 0;)
    for (;;)
    {
        int inChar = toupper(*chPtr);
        //cout << "\n" << (char)inChar << " char id " << inChar << " during state " << state << "\n";
        switch (state)
        {
            
            case START:
            {
                switch (inChar)
                {
                    case '0':
                        state = PREFIX_START;
                        break;
                    default:
                        state = END_FAILURE;
                        break;
                }
                break;
            }

            case PREFIX_START:
            {
                switch (inChar)
                {
                    case 'X':
                        state = PREFIX;
                        break;
                    default:
                        state = END_FAILURE;
                        break;
                }
                break;
            }

            case PREFIX:
            {
                if (inChar == '.')
                {
                    state = NO_WHOLE;
                }
                else if (((inChar >= '0') && (inChar <= '9')) || ((inChar >= 'A') && (inChar <= 'F')))
                {
                    state = WHOLE;
                }
                else
                {
                    state = END_FAILURE;
                }
                break;
            }

            case NO_WHOLE:
            {
                if (((inChar >= '0') && (inChar <= '9')) || ((inChar >= 'A') && (inChar <= 'F')))
                {
                    state = FRACT;
                }
                else
                {
                    state = END_FAILURE;
                }
                break;
            }

            case WHOLE:
            {
                if (inChar == '.')
                {
                    state = FRACT;
                }
                else if (inChar == 'P')
                {
                    state = EXPONENT;
                }
                else if (((inChar >= '0') && (inChar <= '9')) || ((inChar >= 'A') && (inChar <= 'F')))
                {
                    state = WHOLE;
                }
                else
                {
                    state = END_FAILURE;
                }
                break;
            }

            case FRACT:
            {
                if (inChar == 'P')
                {
                    state = EXPONENT;
                }
                else if (((inChar >= '0') && (inChar <= '9')) || ((inChar >= 'A') && (inChar <= 'F')))
                {
                    state = FRACT;
                }
                else
                {
                    state = END_FAILURE;
                }
                break;
            }

            case EXPONENT:
            {
                if ((inChar == '+') || (inChar == '-'))
                {
                    state = SIGNED;
                }
                else if ((inChar >= '0') && (inChar <= '9'))
                {
                    state = DIGIT;
                }
                else
                {
                    state = END_FAILURE;
                }
                break;
            }

            case SIGNED:
            {
                if ((inChar >= '0') && (inChar <= '9'))
                {
                    state = DIGIT;
                }
                else
                {
                    state = END_FAILURE;
                }
                break;
            }

            case DIGIT:
            {
                if ((inChar >= '0') && (inChar <= '9'))
                {
                    state = DIGIT;
                }
                else if ((inChar == 'F') || (inChar == 'L') || (inChar == 0))
                {
                    cout << "\nDeref: " << *chPtr+1 << ",  " << (chPtr + 1) << ", int version " << (char)chPtr + 1 << " isspace: " << isspace(inChar + 1) << "\n";
                    (isspace(inChar+1)) ? state = END_SUCCESS : state = END_FAILURE;
                    //state = END_SUCCESS;
                }
                else
                {
                    state = END_FAILURE;
                }
                break;
            }

            case END_SUCCESS:
            {
                switch (inChar)
                {
                case 'F':
                    return(TYPE_FLOAT);
                    break;
                case 'L':
                    return(TYPE_LDOUBLE);
                    break;
                case 0:
                    return(TYPE_DOUBLE);
                    break;
                default:
                    break;
                }
                break;
            }

            case END_FAILURE:
            {
                return(NO_MATCH);
                break;
            }
            
        }
        if ( state != END_SUCCESS) chPtr++;
        //chPtr++;
    }
    return (NO_MATCH);
}
