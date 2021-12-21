// Write recursive code for Tayler Series

#include <stdio.h>

double taylor_series(double x, double n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = taylor_series(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}
int main()
{
    double r = taylor_series(1, 10);

    printf("%f\n", r);
    return 0;
}