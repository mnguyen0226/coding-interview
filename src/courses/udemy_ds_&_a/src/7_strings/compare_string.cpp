// Function compare two string

#include <stdio.h>

int main()
{
    char A[] = "Painter";
    char B[] = "Painting";
    int i, j, t;

    // get the length of A
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
        {
            break;
        }
    }
    if (A[i] == B[j])
    {
        printf("Two strings are equal\n");
    }
    else if (A[i] < B[j])
    {
        printf("String A[] is smaller than string B[]\n");
    }
    else if (A[i] > B[j])
    {
        printf("String A[] is larger than string B[]\n");
    }

    return 0;
}