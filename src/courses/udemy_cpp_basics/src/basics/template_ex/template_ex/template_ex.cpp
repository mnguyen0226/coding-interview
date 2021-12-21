// template_ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <class T>

T Max(T x, T y) {
    if (x >= y) {
        return x;
    }
    else {
        return y;
    }
}

int main()
{
    std::cout << "Template!\n";
    int c = Max(1, 2);
    cout << c << endl;

    float d = Max(1.2f, 1.33f);
    cout << d << endl;

}

