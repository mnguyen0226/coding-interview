#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// To access heap, use pointer
// Pointer can access the resource outside of programming such as monitor, keyboard
// To create memory memory in heap use mallow
// Every pointer size is 8 bytes
int main(){

    // Create pointer in stack

    int a = 10;
    int *p; // declare a pointer
    p = &a; // store address of a in p

    int A[5] = {1,2,3,4,5};
    int *c = A;

    cout << p << " " << a << endl;

    for(int i = 0; i < 5; i++){
        cout << *c << endl; // use *c for dereference
        c++; // move to the next element 
    }

    // Create pointer to the memory in the heap
    int *t = (int*)malloc(5*sizeof(int));

    p[0] = 10; p[1]= 2; p[3] = 2; p[4] = 5; p[5]=6;

    // Cpp pointer to heap
    int *m = new int[5];
    m[0] = 10; m[1]= 2; m[3] = 2; m[4] = 5; m[5]=6;

    // Release memory / Deallocate memory
    delete []p;
    free(m);

    return 0;
}