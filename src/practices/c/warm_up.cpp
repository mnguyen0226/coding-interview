#include <stdio.h>

int main()
{
    int A[] = {1, 2, 3, 5, 100, -100, 233, 8};
    int smallest = 100000;
    int largest = -100000;
    int len = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < len; i++)
    {
        if (smallest > A[i])
        {
            smallest = A[i];
        }
        if (largest < A[i])
        {
            largest = A[i];
        }
    }
    printf("Len: %d, Smallest: %d, Largest: %d", len, smallest, largest);

    return 0;
}