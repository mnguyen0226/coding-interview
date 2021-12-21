// polymorphism_shape.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write claesses to demonstrate Polymorphism
// Base Class Shape, Derive Class Rectangle, Circle

#include <iostream>

using namespace std;

class Base {
public:
    Base() {}; // Default constructor
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

class Rectangle : public Base{
private:
    float w, h;
public:
    Rectangle(float w = 1, float h = 1) { // Constructor
        this->w = w;
        this->h = h;
    }; // default constructor
    
    float getW() { return w; };
    float getH() { return h; };

    float area() { return w * h; };
    float perimeter() { return 2 * (w + h); };
};

class Circle : public Base {
private:
    float radius;
public:
    Circle(float r = 1) {
        this->radius = r;
    }; // default constructor

    float getR() { return radius; };
    float area() { return radius * radius * 3.14; };
    float perimeter() { return 2 * radius * 3.14; };
};

int main()
{
    std::cout << "Hello World!\n";
    Base *c = new Circle(3);
    cout << c->area() << endl;
    cout << c->perimeter() << endl;

    c = new Rectangle(2, 3);
    cout << c->area() << endl;
    cout << c->perimeter() << endl;

    return 0;
}
