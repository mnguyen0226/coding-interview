// Code up the sum of the natural number using recursion
#include <stdio.h>

int sum_super_natural(int n){ // Time complexity O(1)
    return n*(n+1)/2;
}

int sum_natural(int n) // Time complexity O(n); Space complexity O(n)
{
    if (n == 0)
    {
        return 0;
    }
    return (sum_natural(n - 1) + n);
}

int main()
{
    int r = sum_natural(3);
    printf("%d\n", r);

    int r2 = sum_super_natural(3);
    printf("%d\n", r2);

    int r3 = sum_natural(100);
    printf("%d\n", r3);

    int r4 = sum_super_natural(100);
    printf("%d\n", r4);

    return 0;
}