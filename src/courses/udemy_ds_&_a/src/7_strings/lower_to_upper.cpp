// Function change the lower case and higher case

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[] = "WELCOME";

    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] += 32;
    }

    printf("String Lower: %s\n", s);

    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] -= 32;
    }

    printf("String Upper: %s\n", s);

    // Toggle
    char s1[] = "WeLcOmE";
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s1[i] >= 65 && s1[i] <= 90) // if the char is in upper
        {
            s1[i] += 32; // convert lower
        }
        else if(s1[i] >= 97 && s1[i] <= 122)
        {
            s1[i] -= 32;
        }
    }

    printf("String Toggle: %s\n", s1);

    return 0;
}