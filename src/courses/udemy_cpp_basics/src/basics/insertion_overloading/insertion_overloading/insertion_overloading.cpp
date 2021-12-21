// insertion_overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    // Constructor;
    Complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }

    friend ostream& operator<<(ostream& out, Complex& c);
};

ostream& operator<<(ostream& out, Complex& c) {
    // Rewrite output function
    out << c.real << "+i" << c.img << endl;;
    return out;
}


int main()
{
    Complex c(10, 5);
    cout << c;
}
