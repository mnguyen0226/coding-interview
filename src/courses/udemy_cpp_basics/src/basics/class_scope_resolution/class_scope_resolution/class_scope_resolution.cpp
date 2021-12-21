// class_scope_resolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Rectangle {
private:
    int h, w;

public:
    Rectangle();
    Rectangle(int h, int w);
    Rectangle(Rectangle& r);
    int getHeight() { return h;}
    int getWidth() { return w; }
    void setHeight(int h);
    void setWidth(int w);
    int area();
    int perimeter();
    bool isSquare();
    ~Rectangle();
};

int main()
{
    std::cout << "Hello World!\n";
    Rectangle r1(10, 2);
    cout << r1.area() << endl;
}

Rectangle::Rectangle() {
    h = 1;
    w = 1;
}

Rectangle::Rectangle(int a, int b) {
    h = a;
    w = b;
}

Rectangle::Rectangle(Rectangle& r) {
    h = r.h;
    w = r.w;
}

void Rectangle::setHeight(int h) {
    h = h;
}

void Rectangle::setWidth(int w) {
    w = w;
}

int Rectangle::area() {
    return h * w;
}

int Rectangle::perimeter() {
    return 2 * (h + w);
}

bool Rectangle::isSquare() {
    return h == w;
}

Rectangle::~Rectangle() {
    cout << "Rectangle Destroyed" << endl;
}

 