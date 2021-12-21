// class_create_objects.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Create object in stack and heap

#include <iostream>
using namespace std;

class Rectangle {
public:
    int h, w;

    int area() {
        return h * w;
    }

    int perimeter() {
        return 2 * (h + w);
    }
};

int main()
{
    std::cout << "Hello World!\n";
    
    // Createt object on stack. We can access object via pointer
    // With stack you can access object variable directly or via pointer
    Rectangle r1;
    Rectangle* ptr;
    ptr = &r1;
    ptr->h = 10;
    ptr->w = 2;
    cout << ptr->area() << endl;
    cout << ptr->perimeter() << endl;

    // Create in heap
    Rectangle* ptr = new Rectangle();
    ptr->h = 10;
    ptr->w = 2;
    cout << ptr->area() << endl;
    cout << ptr->perimeter() << endl;
}
