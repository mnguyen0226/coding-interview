// class_constructors_types.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Rectangle {
private:
    int h, w;
public:
    // Constructor
    Rectangle() { // default
        h = 1;
        w = 1; 
    }

    Rectangle(int a=2, int b=3) { // set constructor, we might now need default constructor
        h = a;
        w = b;
    }

    // Copy Constructor, shallow copy
    Rectangle(Rectangle& r) {
        h = r.h;
        w = r.w;
    }

    // Functions
    int area() {
        return h * w;
    }

};

int main()
{
    std::cout << "Hello World!\n";
    Rectangle r1;
    cout << r1.area() << endl;

    Rectangle r2(1, 2);
    cout << r2.area() << endl;

    Rectangle r3(r2);
    cout << r3.area() << endl;
}
