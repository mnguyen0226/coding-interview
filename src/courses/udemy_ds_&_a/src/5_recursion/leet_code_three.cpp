// Power/Exponential using recursion

#include <stdio.h>

int exponential(int n, int m)
{ // n = number , m is the exponential
    if (m == 0)
    {
        return 1;
    }
    return (exponential(n, m - 1) * n);
}

int reduce_exponential(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    if (m % 2 == 0)
    {
        return reduce_exponential(n * n, m / 2);
    }
    else
    {
        return n * reduce_exponential(n * n, (m - 1) / 2);
    }
}

int main()
{
    int r = exponential(2, 5);
    printf("%d\n", r);

    int r2 = reduce_exponential(2, 5);
    printf("%d\n", r2);

    return 0;
}