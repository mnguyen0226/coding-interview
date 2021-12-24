#include <stdio.h>

int main(){
    int num, *p;
    printf("Please enter a number: ");
    scanf("%d", &num);
    p = &num;
    printf("Number: %d", *p);

    return 0;
}