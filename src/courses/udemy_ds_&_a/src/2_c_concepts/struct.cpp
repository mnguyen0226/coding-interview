#include <stdio.h>
#include <iostream>
using namespace std;

// How to define the structures
struct Rectangle{
    int length; // 2 bytes
    int breadth; // 2 bytes
    char x; // 1 byte
};

int main(){
    printf("Starting \n");

    // Declare a struct
    struct Rectangle r1;

    // Declare directly
    struct Rectangle r2={1,2,'1'};

    printf("%lu", sizeof(r2)); // should be 4 = 2+2 bytes

    return 0; 
}