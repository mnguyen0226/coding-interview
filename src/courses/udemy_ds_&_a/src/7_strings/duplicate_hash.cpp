// Function finds the duplication in the String using hashtable

#include <stdio.h>

int main()
{
    char A[] = "finding";
    int H[26], i;
    for (int t = 0; t < 26; t++)
    {
        H[t] = 0;
    }

    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97] += 1;
    }

    for (int j = 0; j < 26; j++)
    {
        if (H[j] > 1)
        {
            printf("Repetitive letter is: %c\n", j + 97);
            printf("%d\n", H[j]);
        }
    }

    return 0;
}