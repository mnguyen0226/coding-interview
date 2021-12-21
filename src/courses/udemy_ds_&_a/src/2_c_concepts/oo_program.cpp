#include <iostream>
#include <stdio.h>

using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    // constructor
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    // calculate the area
    int area()
    {
        return length * breadth;
    }

    // calculate the parameter
    int perimeter()
    {
        int p;
        p = 2 * (length + breadth);
        return p;
    }
};
// User interaction
int main()
{
    Rectangle r(5, 6);

    int a = r.area();
    int p = r.perimeter();

    printf("Area = %d\nPerimeter = %d\n", a, p);

    return 0;
}