#include <stdio.h>
int main()
{
    char c;
    printf("Please enter a character: ");
    scanf("%c", &c);
    if (c >= 65 && c <= 90)
    {
        printf("Uppercase");
    }
    else
    {
        printf("Lowercase");
    }

    return 0;
}