// static_member_class_ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Create a program that can create student and keep track of the addmission number

#include <iostream>

using namespace std;

class Student {
public:
    int rollNum;
    static int adminNum;

    // Constructor
    Student() {
        adminNum++;
        rollNum = adminNum;
    };
};

int Student::adminNum = 0; // Have to initialize the static member of the class outside

int main()
{
    std::cout << "Hello World!\n";
    Student s1;
    cout << s1.rollNum << endl;

    Student s2;
    cout << s2.rollNum << endl;

    return 0;
}
