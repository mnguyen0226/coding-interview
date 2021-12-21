// innerClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Outer{
private:
    class Inner {
    public:
        void display() {
            cout << "Display of Inner" << endl;

        }
    };
public:

    Inner i; // create class Inner

    void fun() {
        i.display();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
