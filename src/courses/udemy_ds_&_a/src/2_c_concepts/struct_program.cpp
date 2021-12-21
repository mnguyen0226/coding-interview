#include <iostream>
#include <stdio.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int area(Rectangle r)
{
    return r.length * r.breadth;
}

int perimeter(Rectangle r)
{
    int p;
    p = 2 * (r.length + r.breadth);
    return p;
}

// User interaction
int main()
{
    Rectangle r = {0, 0};

    printf("Enter Length and Breadth:\n");
    cin >> r.length >> r.breadth;

    int a = area(r);
    int p = perimeter(r);

    printf("Area = %d\nPerimeter = %d\n", a, p);

    return 0;
}