// Function count number of word in the sentence

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[] = "How are you";
    int count_word = 1; // count the last word since there is no spacing in the end of the sentence
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i - 1] != ' ')
        {
            count_word++;
        }
    }
    printf("Count: %d", count_word);

    return 0;
}