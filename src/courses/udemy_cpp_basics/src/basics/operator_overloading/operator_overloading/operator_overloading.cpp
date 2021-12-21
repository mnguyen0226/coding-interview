// operator_overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
// operator overloading for class object

#include <iostream>
using namespace std;

class Complex {
private:
    int real, img;
public:
    // Constructor
    Complex(int real=0, int img=0) { // Make this both parameterize and default constructor
        this->real = real;
        this->img = img;
    }

    // Create an add function for thhis Complex number to another Complext number
    Complex add(Complex x) {
        Complex temp; // store result
        temp.real = this->real + x.real;
        temp.img = this->img + x.img;

        return temp;
    }

    Complex operator-(Complex x) {
        Complex temp;
        temp.real = this->real - x.real;
        temp.img = this->img - x.img;

        return temp;
    }

    int getReal() {
        return real;
    }
    int getImg() {
        return img;
    }
};


int main()
{
    std::cout << "Hello World!\n";
    Complex a(1, 2);
    Complex b(2, 3);
    a = a.add(b);
    cout << a.getReal() << " " << a.getImg() << endl;

    Complex c = a - b;

    cout << c.getReal() << " " << c.getImg() << endl;
}

