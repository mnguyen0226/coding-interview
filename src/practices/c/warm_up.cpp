#include <stdio.h>
int main()
{
    int d;
    int final = 0;
    printf("Please enter a 3 digits number: ");
    scanf("%d", &d);

    int first = d / 100;
    d = d % 100;

    int second = d / 10;
    int third = d % 10;

    final = third * 100 + second * 10 + first;

    printf("Reversed number is: %d\n", final);

    return 0;
}