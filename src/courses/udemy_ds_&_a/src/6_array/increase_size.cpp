// Mechanism to increase the array size dynamically
// In the case that we reach the max capacity of the array,
// we double the size and move elements from old array to new array

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // create original array
    int *p = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        p[i] = i + 1;
    }

    // create a larger array
    int *q = new int[10];
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    // deallocate memory to avoid memory leak
    delete[] p;
    p = q; // let point p to new array q
   
    // set q as null pointer
    q = NULL;
}