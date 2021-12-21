#include <stdio.h>

int main()
{
    char A[] = "python";
    char temp;

    // for loop that trace j to the end of the character
    int i, j;
    for (j = 0; A[j] != '\0'; j++) // after check condition for A[j] and execute, j then being increment
    {
    }
    j--; // move back to n
    for (i = 0; i < j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    printf("Reversed String: %s", A);

    return 0;
}