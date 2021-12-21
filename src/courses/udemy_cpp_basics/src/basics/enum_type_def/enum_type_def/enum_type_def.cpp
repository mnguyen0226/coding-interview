// enum_type_def.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

using namespace std;

enum day {mon, tue, wed, thr, fri, sat, sun};
enum dept {cs, ece, it, mech};

// #define mon 0
// const int mon = 0

typedef int marks; // for renaming the datatype when declare a variable
typedef char bruh;

int main()
{
    day d;

    d = mon;

    cout << d << endl;
    cout << sat << endl;

    marks m1, m2;
    m1 = 50;

    bruh s1[7] = "Hello";

    cout << s1 << endl;

    return 0;
}
