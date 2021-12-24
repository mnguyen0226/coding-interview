#include <stdio.h>
#define abs(a) (a < 0 ? (-1 * a) : a)
int main()
{
    double a = -1.0;
    printf("The absolute number is: %f", abs(a));

    return 0;
}