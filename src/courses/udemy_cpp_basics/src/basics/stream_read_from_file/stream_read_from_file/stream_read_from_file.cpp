// stream_read_from_file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    ifstream ifs("My.txt");

    if (ifs) { // ifs.is_open()
        cout << "File is Open" << endl;
    }
    string name;
    int roll;
    string branch;

    ifs >> name >> roll >> branch;

    cout << name << endl;
    cout << roll << endl;
    cout << branch << endl;

    ifs.close();

    return 0;
}
