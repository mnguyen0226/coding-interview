// Find the factorial of a number

#include <stdio.h>

int factorial(int n) // Time complexity = O(n)
{
    if (n == 0)
    {
        return 1;
    }
    return (factorial(n - 1) * n);
}

int main()
{
    int r = factorial(5);
    printf("%d\n", r);
    return 0;
}