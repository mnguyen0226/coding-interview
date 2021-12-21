#include <stdio.h>

int func(int n){
    if(n > 100){
        return n - 10;
    }
    return func(func(n+11));
}

int main(){
    int r = func(95);
    int r2 = func(100);
    printf("%d\n", r);
    printf("%d", r2);

    return 0;
}