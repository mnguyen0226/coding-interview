// Function checks if the string is palindrome or not
// Make a reverse of the string, if the are equal then it is palindrome

#include <stdio.h>

int main()
{
    int i, j;
    char A[] = "madam";
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i--;

    // find the reverse of this string
    char B[6];
    for (j = 0; i >= 0; j++, i--)
    {
        B[j] = A[i];
    }
    B[j] = '\0';

    // Trace through both array
    for (i = 0, j = 0; A[i] != '\0' || B[i] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
        {
            break;
        }
    }

    // If both string is end at \0 after the trace
    if (A[i] == '\0' && B[j] == '\0')
    {
        printf("The string is palindrome. \n");
    }
    else
    {
        printf("The string is not palindrome. \n");
    }

    return 0;
}
