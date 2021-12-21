// stream_write_to_file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    ofstream ofs("My.txt", ios::trunc);
    ofs << "John" << endl;
    ofs << 25 << endl;
    ofs.close();
    
    return 0;
}

