/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts
 * 132297 Ray Mitchell
 * 08/20/2018
 * C1A6E2_MyStrcmp.c
 * Win 10
 * Visual C++ 2017
 *
 * Traverses down both entered strings and compares the characters
 * of both one at a time until a mismatch or a null character is reached.
 */

int MyStrcmp(const char *s1, const char *s2)
{
    int result = 0;

    // Continues until a mismatch is found or null character is found. 
    for (int index = 0; (s1[index] != '\0') && (s2[index] != '\0') && (result == 0); index++)
    {
        // Anything other than a 0 will cause the next iteration to be skipped
        result = s1[index] - s2[index];
    }

    return result;
}
