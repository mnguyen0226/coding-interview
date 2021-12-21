// class_string_methods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    std::cout << "Class String Methods!\n";
    string s = "Minh Nguyen";
    
    // string length / size
    cout << "The length/size is: " << s.length() << " " << s.size() << endl;

    // string capacity
    cout << "The capacity is: " << s.capacity() << endl; // why? the capacity is bigger than size depends on the compiler or the class

    // string resize
    s.resize(5);
    cout << "Resize the string: " << s << endl;

    // string max size
    cout << "Check max size: " << s.max_size() << endl;

    // string clear
    s.clear();
    cout << "Clear string: " << s << endl;

    s = "Hahahah";

    // string empty
    //s.empty();
    //cout << "Empty string: " << s << endl; // why? Check if the string empty or not 
    if (s.empty()) {
        cout << "String is empty!" << endl;
    }
    else {
        cout << "String is not empty!" << endl;
    }

    return 0;
}

