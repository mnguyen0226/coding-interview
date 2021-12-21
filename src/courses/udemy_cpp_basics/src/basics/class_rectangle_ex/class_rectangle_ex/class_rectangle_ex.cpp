// class_rectangle_ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Rectangle {
    // if not declare public, this is by default private
    public:

        // Parameters
        int height; // 2 bytes for int
        int width; // 2 byted for int
    
        // Functions
        int area() {
            return height * width;
        }

        int perimeter() {
            return 2*(height + width);
        }
};

int main()
{
    std::cout << "Hello World!\n";

    Rectangle r1, r2; // objects, creaed on the stack with 4 bytes each
    r1.height = 10;
    r1.width = 2;
    cout << "The area of r1 is: " << r1.area() << endl;

}
