// inheritant_ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Rectangle {
private:
    int w, h;
public:
    // Constructor
    Rectangle(int w = 0, int h = 0) {
        this->w = w;
        this->h = h;
    };

    int getWidth() { return w; };
    int getHeight() { return h; };
    void setWidth(int w) { this->w = w; };
    void setHeight(int h) { this->h = h; };
    int area() {
        return w * h;
    };
    int perimeter() {
        return 2 * (w + h);
    };
};

// Class inheritant. Inherit publicly
class Cuboid :public Rectangle {
private:
    int tall;
public:
    Cuboid(int w = 0, int h = 0, int tall = 0) { // Default constructor
        this->tall = tall;
        setWidth(w); // inheritant from rectangle class
        setHeight(h); // inheritant from rectangle class
    };

    int getTall() {
        return tall; 
    };

    void setTall(int t) {
        this->tall = t;
    };

    int volumne() {
        return getWidth() * getHeight() * this->tall;
    }
};


int main()
{
    std::cout << "Hello World!\n";
    
    Cuboid c(10, 5, 2);
    cout << c.volumne() << endl;
}

