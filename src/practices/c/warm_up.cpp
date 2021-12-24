#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "This is an umbrella eeeeee is is is";
    int count_e = 0;
    int count_is = 0;

    // traverse through all characters
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'e')
            count_e++;
    }

    // parse the string to find words
    char *pch = strtok(s, " ");
    while (pch != NULL)
    {
        if (strcmp(pch, "is") == 0)
            count_is++;
        pch = strtok(NULL, " ");
    }
    printf("Counter: %d, %d", count_e, count_is);

    return 0;
}