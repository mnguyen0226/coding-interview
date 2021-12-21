// class_data_hiding_ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Rectangle {
private:
    int w, h;
public:
    // Since we make the data private, we have to set the data
    // Setter
    void setHeight(int a) {
        if (a >= 0)
            h = a;
        else
            h = 0;
    }

    void setWidth(int b) {
        if (b >= 0)
            w = b;
        else
            w = 0;
    }

    // Getter
    int getHeight() {
        return h;
    }

    int getWidth() {
        return w;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Rectangle r;
    r.setHeight(10);
    r.setWidth(2);
    cout << r.getHeight() << endl;
    cout << r.getWidth() << endl;
}

