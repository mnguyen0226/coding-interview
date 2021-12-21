// Find the length of the string
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[] = "Welcome"; // automatically fill out /0
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) // don't need to count \0
    {
        count++;
    }

    printf("Count: %d\n", count);

    return 0;
}