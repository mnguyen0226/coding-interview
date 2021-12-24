#include <stdio.h>
#include <string.h>

int main()
{
    char name[] = "Nguyen Tran Binh Minh";
    int num_letter = 4;
    int count = 1;

    // parse through the string, find the last element.
    char *pch = strtok(name, " "); // get the first token
    while (pch != NULL)
    {
        if (count == 4)
        {
            printf("%s ", pch);
        }
        else{
            printf("%c. ", pch[0]);
        }
        pch = strtok(NULL, " ");
        count++;
    }

    return 0;
}