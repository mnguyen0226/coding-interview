// Time complexity = O(2^n)

#include <stdio.h>

// n number of disk, order A, B, C columns
void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("(%d, %d) \n", A, C); // <- top-disk movement
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    TOH(3, 1, 2, 3); // Objective is to find the movement of the top disk that allows to move all the disk to C
    return 0;
}
