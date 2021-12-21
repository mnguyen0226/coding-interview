// Find the result of the Fibonacci Series

#include <stdio.h>

int fib(int n) // Run time: O(2^n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

// There are too much excessive calls in the function above, thus, we will store the calculated value in the array
// This approach is called memorization
int F[10];

int fib_mem(int n) // Run time: O(n) due to array access
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = fib_mem(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = fib_mem(n - 1);
        }
        F[n] = F[n-2] + F[n-1];
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }

    int r = fib(7);
    printf("%d\n", r);

    int r2 = fib_mem(7);
    printf("%d\n", r2);

    return 0;
}