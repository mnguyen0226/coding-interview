#include <iostream>
#include <stdio.h>

using namespace std;

int area(int length, int breadth)
{
    return length * breadth;
}

int perimeter(int length, int breadth)
{
    int p;
    p = 2 * (length + breadth);
    return p;
}

// User interaction
int main()
{
    int length, breadth = 0;

    printf("Enter Length and Breadth:\n");
    cin >> length >> breadth;

    int a = area(length, breadth);
    int p = perimeter(length, breadth);

    printf("Area = %d\nPerimeter = %d\n", a, p);

    return 0;
}