#include <stdio.h>
int main()
{
    int length, breadth;
    printf("Please enter the length and breadth values: ");
    scanf("%d", &length);
    scanf("%d", &breadth);
    if (length == breadth)
    {
        printf("The rectangle is square.");
    }
    else
    {
        printf("The rectangle is NOT square.");
    }

    return 0;
}