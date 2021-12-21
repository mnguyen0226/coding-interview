// Function count the number of vowel or consonents

#include <stdio.h>

int main()
{
    char A[] = "How are you";
    int count_vowel = 0;
    int count_consonent = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'i' || A[i] == 'o' || A[i] == 'e' || A[i] == 'u' || A[i] == 'A' || A[i] == 'I' || A[i] == 'O' || A[i] == 'E' || A[i] == 'U')
        {
            count_vowel++;
        }
        // Make sure not counting the space
        // This is an odd condition, if not ueoai then, we check lower and upper case including ueoai but not spacing character
        else if ((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122))
        {
            count_consonent++;
        }
    }
    printf("Consonent: %d, Vowel: %d", count_consonent, count_vowel);

    return 0;
}