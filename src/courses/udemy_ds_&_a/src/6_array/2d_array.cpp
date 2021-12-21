#include <stdio.h>
#include <stdlib.h>

int main()
{
    // create in stack
    int A[3][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {1, 5, 9, 7}};

    int *B[3]; // this create in stack but each array in array B will be create in heap
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = (int *)malloc(4 * sizeof(int));

    // both dimension is created in the heap
    int **C;
    C = (int **)malloc(3 * sizeof(int *));
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = (int *)malloc(4 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}