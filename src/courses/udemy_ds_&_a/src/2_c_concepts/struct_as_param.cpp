#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

// Passed by address
void func(struct Rectangle *r)
{
    r->length = 20;
    cout << "Length: " << r->length << " Breadth: " << r->breadth << endl;
}

// Passed by reference
void func2(struct Rectangle &r)
{
    r.length = 20;
    cout << "Length: " << r.length << " Breadth: " << r.breadth << endl;
}

// Create a rectangle using pointer in heap
struct Rectangle *create_r(){
    struct Rectangle *r;
    r = new Rectangle;

    r->breadth = 15;
    r->length = 10;
    return r;
}

int main()
{
    struct Rectangle r = {10, 5};
    func(&r);
    func2(r);

    cout << "Length: " << r.length << " Breadth: " << r.breadth << endl;

    Rectangle *r2 = create_r();
    func2(*r2);

    return 0;
}