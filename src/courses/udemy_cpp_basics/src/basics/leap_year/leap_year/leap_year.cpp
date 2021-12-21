// leap_year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// All years which are perfectly divisible by 4 are leap years except for century years (year ending with 00) 
// which is leap year only it is perfectly divisible by 400

#include <iostream>
using namespace std;

bool check_leap_year(int year);

int main()
{
    std::cout << "Leap Year\n";
    int year;
    cout << "Please enter a year: ";
    cin >> year;

    if (check_leap_year(year)) {
        cout << "Year " << year << " is leap.";
    }
    else {
        cout << "Year " << year << " is not leap.";
    }

    return 0;
}

bool check_leap_year(int year) {
    // Check if century year or not
    // Check if the last 2 numbers are 0 or not
    bool r = true;

    if (year % 100 == 0) {
        if (year % 400 == 0) {
            return r;
        }
    }
    else {
        if (year % 4 == 0) {
            return r;
        }
    }
    return !r;
}
