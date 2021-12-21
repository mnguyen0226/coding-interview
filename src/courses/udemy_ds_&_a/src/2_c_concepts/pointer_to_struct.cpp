// Every pointer takes only 2 bytes
// *p = the variable/object
// p = address
// &p = reference = another name

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    // Create a rectangle object
    Rectangle r = {10, 5};
    cout << r.length << endl;
    cout << r.breadth << endl;

    Rectangle *p = &r; // pointer to a structure. This is not reference
    cout << p->length << endl;
    cout << p->breadth << endl;

    // Create object in heap with pointer
    Rectangle *t;
    t = (Rectangle *)malloc(sizeof(Rectangle));

    // Set
    t->length = 15;
    t->breadth = 10;

    cout << t->length << endl;
    cout << t->breadth << endl;

    return 0;
}