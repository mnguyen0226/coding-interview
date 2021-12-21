// Function check if two strings are anagram or not
// Assume that two strings are distinct and we got the lower case, else we have to deduce with 122 instead of 97
// We will use hash table

#include <stdio.h>

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    bool not_anagram = false;
    // Create a hash table, initialize with 0
    char H[26]; // there are 26 letter total in the alphabet
    for (int i = 0; i < 26; i++)
    {
        H[i] = 0;
    }

    // Trace through A and increment in the hash table
    for (int i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }

    // Trace through B and decrement in the hash table
    for (int i = 0; B[i] != '\0'; i++)
    {
        H[A[i] - 97]--;
    }

    // Check if there is any 1, if there is then it is not anagram
    for (int i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            printf("The two strings are not anagram.\n");
            not_anagram = true;
            break;
        }
    }
    if (!not_anagram)
    {
        printf("The Two strings are anagram.\n");
    }

    return 0;
}