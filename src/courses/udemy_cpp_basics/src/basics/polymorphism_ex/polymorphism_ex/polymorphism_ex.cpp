// polymorphism_ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Car{
public:
    // Pure virtual class
    virtual void start() = 0;

};

class Innova :public Car
{
public:
    //void start(){
    //    cout << "Innova Start" << endl;
    //}
};

int main()
{
    std::cout << "Hello World!\n";
    Innova c;
    c.start();

    return 0;
}
