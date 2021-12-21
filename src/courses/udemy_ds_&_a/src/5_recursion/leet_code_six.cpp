// Calculate the combination formular with recursion

#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return (factorial(n - 1) * n);
}

double comb(int n, int r) // Time complexity = O(n)
{
    if (r <= n)
    {
        return (factorial(n) / (factorial(r) * factorial(n - r)));
    }
    return -1;
}

int main()
{
    double r = comb(5, 1);
    printf("%f\n", r);

    return 0;
}