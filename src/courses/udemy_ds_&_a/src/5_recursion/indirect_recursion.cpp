// Indirect recursion with two functions calling each other back and forth

#include <stdio.h>

void funcA(int n);
void funcB(int n);

void funcA(int n){
    if(n > 0){
        printf("%d, ", n);
        funcB(n-1);
        printf("%d; ", n);
    }

}

void funcB(int n){
    if(n > 0){
        printf("%d, ", n);
        funcA(n/2);
        printf("%d; ", n);
    }
}

int main(){
    funcA(20);
    return 0;
}